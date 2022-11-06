#include <cstdio>
#include <iostream>
#define MN 55

int a[MN][MN], n;

void solve(int A, int B, int C, int D)
{
	if(C <= n && D <= n)
	{
		printf("? %d %d %d %d\n", A, B, C, D);
		fflush(stdout);
		int x; scanf("%d", &x);
		a[C][D] = a[A][B] ^ x ^ 1;
	}
}

int main()
{
	scanf("%d", &n);
	a[1][1] = 1; a[1][2] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(i == 2 && j == 1) a[i][j] = a[i + 1][j + 1], solve(i, j, i + 1, j + 1), std::swap(a[i][j], a[i + 1][j + 1]);
			if(i == 1) solve(i, j, i, j + 2);
			if(j == 1) solve(i, j, i + 2, j);
			if(i == 1 && j == 2) solve(i, j, i + 2, j);
			if(i != 2 || j != 1) solve(i, j, i + 1, j + 1);
		}

	int nx = 1, ny = 1;
	int tx = 1, ty = 1, v = a[1][1];
	int ans;
	for(int i = 1; i <= 3; i++)
	{
		if(ty < n) ty++;
		else tx++;
		v ^= a[tx][ty];
	}
	
	while(1)
	{
		if(!v)
		{
			printf("? %d %d %d %d\n", nx, ny, tx, ty);
			fflush(stdout);
			int x; scanf("%d", &x);
			ans = a[nx][ny] ^ a[tx][ty] ^ x ^ 1;
			break;
		}
		if(ty < n) ty++;
		else tx++;
		v ^= a[tx][ty];
		v ^= a[nx][ny];
		if(ny < n) ny++;
		else nx++; 
	}
	
	puts("!");
	for(int i = 1; i <= n; i++, puts(""))
		for(int j = 1; j <= n; j++)
			if((i + j) & 1) printf("%d", a[i][j] ^ ans);
			else printf("%d", a[i][j]);
	fflush(stdout);
}