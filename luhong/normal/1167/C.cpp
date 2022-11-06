#include <cstdio>
#include <iostream>

int fa[501000], siz[501000];

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= m; i++)
	{
		int k; scanf("%d", &k);
		int lst = 0;
		for(int j = 1; j <= k; j++)
		{
			int x; scanf("%d", &x);
			if(lst) 
			{
				int a = Find(lst), b = Find(x);
				if(a != b) fa[a] = b, siz[b] += siz[a];
			}
			lst = x;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", siz[Find(i)]);
}