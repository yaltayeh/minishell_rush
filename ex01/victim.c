#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*
	send output to file called 'out'

	check if run execve in child process
	make redirection output and send args

	$ cat -e out
	fd: 3$
	ppid: 45030$
	argv[0]: ./victim.elf$
	argv[1]: arg1$
	argv[2]: arg2$
	argv[3]: arg3$
*/

int main(int argc, char **argv)
{
	int	fd;
	int	i;

	fd = open("/dev/null", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	printf("fd: %d\n", fd);
	close(fd);
	printf("ppid: %d\n", getppid());
	i = 0;
	while (i < argc)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}
