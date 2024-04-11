#include <stdio.h>
#define MAXN 3005

int n, m, p[MAXN], f[MAXN], cnt;
bool vis[MAXN];

int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
inline void merge(int a, int b){f[find(a)] = find(f[b]);}
inline void swap(int& a, int& b){int t = a; a = b; b = t;}
void getCycle(int pos)
{
	vis[pos] = true;
	while(!vis[p[pos]])
	{
		merge(pos, p[pos]);
		pos = p[pos];
		vis[pos] = true;
	}
}
void cleanData(int pos)
{
	vis[pos] = false;
	f[pos] = pos;
	while(vis[p[pos]])
	{
		vis[p[pos]] = false;
		f[p[pos]] = p[pos];
		pos = p[pos];
	}
}
int init()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &p[i]);
	scanf("%d", &m);
	return 0;
}
int solve()
{
	int i, j;
	for(i = 1; i <= n; i ++)
		f[i] = i;
	for(i = 1; i <= n; i ++)
		if(!vis[i])
		{
			getCycle(i);
			cnt ++;
		}
	if(n - cnt == m)
	{
		printf("0\n");
		return 0;
	}
	if(n - cnt > m)
	{
		printf("%d\n", n - cnt - m);
		for(i = 1; i <= n && n - cnt != m; i ++)
			if(i != p[i])
				for(j = i + 1; j <= n; j ++)
					if(find(i) == find(j))
					{
						printf("%d %d\n", i, j);
						cleanData(i);
						swap(p[i], p[j]);
						getCycle(i);
						getCycle(j);
						cnt ++;
						i = 0;
						break;
					}
	}
	else
	{
		printf("%d\n", m - n + cnt);
		for(i = 2; i <= n && n - cnt != m; i ++)
			if(find(i) != find(1))
			{
				swap(p[1], p[i]);
				merge(1, i);
				printf("1 %d ", i);
				cnt --;
				i = 1;
			}
	}
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}