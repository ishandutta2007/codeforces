#include <iostream>
#include <cstdio>
#define MN 1010
#define mod 2520

int f[MN][mod];
int st[MN * mod][2], top = 0;
bool inq[MN][mod], used[MN];
int e[MN][10], k[MN], m[MN];

int dfs(int x, int y)
{
	if(inq[x][y])
		for(int i = top; i; i--)
		{
			if(!used[st[i][0]]) used[st[i][0]] = 1, f[x][y]++;
			if(st[i][0] == x && st[i][1] == y) break;
		}
		
	if(f[x][y])
	{
		while(top)
		{
			used[st[top][0]] = 0;
			inq[st[top][0]][st[top][1]] = 0;
			top--;
		}
		return f[x][y];
	}
	
	st[++top][0] = x; st[top][1] = y; inq[x][y] = 1;
	int ny = ((y + k[x]) % mod + mod) % mod;
	f[x][y] = dfs(e[x][ny % m[x]], ny);
	return f[x][y];
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &k[i]);
	
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &m[i]);
		for(int j = 0; j < m[i]; j++) scanf("%d", &e[i][j]);
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < mod; j++) dfs(i, j);
	
	int q; scanf("%d", &q);
	while(q--)
	{
		int x, y; scanf("%d%d", &x, &y);
		y = (y % mod + mod) % mod;
		printf("%d\n", f[x][y]);
	}
	return 0;
}