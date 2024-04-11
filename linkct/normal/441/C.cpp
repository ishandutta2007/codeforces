#include <stdio.h>

int n, m, k, nx, ny;
void next_position()
{
	printf("%d %d ", nx, ny);
	if(nx % 2)
		if(ny == m)
			nx ++;
		else
			ny ++;
	else
		if(ny == 1)
			nx ++;
		else
			ny --;
}
void print_tube()
{
	int cnt = 0;
	printf("%d ", n * m / k);
	for(int i = 1; i <= n * m / k; i ++)
		next_position();
	printf("\n");
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	nx = ny = 1;
	for(int i = 1; i < k; i ++)
		print_tube();
	if(nx > n)
		return 0;
	int cnt = (n - nx) * m + (nx % 2 ? (m - ny + 1) : ny);
	printf("%d ", cnt);
	for(int i = 1; i <= cnt; i ++)
		next_position();
	return 0;
}