#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int md = 993217;
int test, n, m, k, x, y, deg[111111], flg, del[111111], cur[1111], cnt;
vector<int> g[111111];
set<pair<int, int> > s;
bool can;
struct hashtable
{
	int head[md + 5], nxt[444444], cnt;
	long long val[444444];
	void add(long long x)
	{
		int g = x % md;
		++cnt;
		val[cnt] = x;
		nxt[cnt] = head[g]; head[g] = cnt;
	}
	int find(long long x)
	{
		int g = x % md;
		for (int i = head[g]; i; i = nxt[i])
		{
			if (val[i] == x) return 1;
		}
		return 0;
	}
	void clear()
	{
		for (int i = 1; i <= cnt; i++)
		{
			nxt[i] = 0;
			head[val[i] % md] = 0;
		}
		cnt = 0;
	}
}ht;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; i++) 
		{
			g[i].clear();
			del[i] = 0;
			deg[i] = 0;
		}
		ht.clear();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
			ht.add(1ll * x * (n + 1) + y);
			ht.add(1ll * y * (n + 1) + x);
			deg[x] ++;
			deg[y] ++;
		}
		if (k >= 500)
		{
			printf("-1\n");
			continue;
		}
		s.clear();
		for (int i = 1; i <= n; i++)
		{
			s.insert(make_pair(deg[i], i));
		}
		flg = 0;
		while(!s.empty())
		{
			x = s.begin() -> second;
			if (deg[x] >= k) break;
			s.erase(s.begin());
			del[x] = 1;
			if (deg[x] == k - 1)
			{
				can = 1;cnt = 0;
				for (int i = 0; i < g[x].size(); i++)
				{
					int to=g[x][i];
					if (!del[to]) cur[++cnt] = to;
				}
				for (int i = 1; i <= cnt; i++)
				{
					for (int j = i + 1; j <= cnt; j++)
					{
						if (!ht.find(1ll * cur[i] * (n + 1) + cur[j])) 
						{
							can = 0;
							break;
						}
					}
					if (!can) break;
				}
				if (can)
				{
					flg = 1;
					printf("2\n%d ",x);
					for (int i = 1; i <= cnt; i++)
					{
						printf("%d ", cur[i]);
					}
					printf("\n");
					break;
				}
			}
			for (int i = 0; i < g[x].size(); i++)
			{
				int to=g[x][i];
				if (!del[to])
				{
					s.erase(s.find(make_pair(deg[to], to)));
					deg[to] --;
					s.insert(make_pair(deg[to], to));
				}
			}
		}
		if (!flg && !s.empty())
		{
			printf("1 %d\n", (int)s.size());
			for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); it++)
			{
				printf("%d ", it -> second);
			}
			printf("\n");
		}
		else if (!flg)
		{
			printf("-1\n");
		}
	}
	return Accepted;
}