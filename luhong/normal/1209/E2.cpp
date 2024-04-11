#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MN 13
#define MM 2010

int T;
struct xxx{
	int v, r, c;
}d[MN * MM];

int id[MN], a[MN][MM];
int v[MN][1 << MN], f[MN][1 << MN];
bool used[MM];

bool cmp(xxx a, xxx b) {return a.v > b.v;}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(v, 0, sizeof(v));
		memset(f, 0, sizeof(f));
		memset(used, 0, sizeof(used));
		
		int n, m; scanf("%d%d", &n, &m);
		int tot = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);
				++tot, d[tot].r = i, d[tot].c = j, d[tot].v = a[i][j];
			}
		
		std::sort(d + 1, d + tot + 1, cmp);
		int k = 0;
		for(int i = 1; i <= tot; i++)
		{
			if(!used[d[i].c])
			{
				used[d[i].c] = 1; id[++k] = d[i].c;
				if(k == n) break;
			}
		}
		
		for(int i = 1; i <= k; i++)
			for(int S = 1; S < (1 << n); S++)
			{
				int T = S, now = 0;
				for(int j = 0; j < n; j++)
					if((S >> j) & 1) now += a[j][id[i]];
				for(int j = 0; j < n; j++)
				{
					T = (T >> 1) + ((T & 1) << (n - 1));
					v[i][T] = std::max(v[i][T], now);
				}
			}
		
		for(int i = 1; i <= k; i++)
			for(int S = 0; S < (1 << n); S++)
			{
				f[i][S] = f[i - 1][S];
				for(int j = S; j &= S; j--)
					f[i][S] = std::max(f[i][S], f[i - 1][S ^ j] + v[i][j]);
			}
		
		printf("%d\n", f[k][(1 << n) - 1]);
	}
}