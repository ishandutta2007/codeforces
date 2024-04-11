#include <cstdio>
#include <iostream>
#include <vector>
#define T 316
#define MN 101000

typedef long long ll;

std::vector<int> v1[MN], v2[MN], v3[MN];
ll ans;
int in[MN], out[MN], d[MN];
int w[MN];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		d[a]++; d[b]++;
		if(a < b) in[a]++, out[b]++;
		else in[b]++, out[a]++;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
	{
		ans += 1ll * in[i] * out[i];
		w[i] = i;
		for(int j = 0; j < v1[i].size(); j++)
		{
			if(d[v1[i][j]] > T) v2[i].push_back(v1[i][j]);
			if(d[i] > T && d[v1[i][j]] <= T && i < v1[i][j]) v3[i].push_back(v1[i][j]);
		}
	}
	int q; scanf("%d", &q);
	printf("%lld\n", ans);
	for(int j = 1; j <= q; j++)
	{
		int x; scanf("%d", &x);
		ans -= 1ll * in[x] * out[x];
		if(d[x] <= T)
		{
			for(int i = 0; i < v1[x].size(); i++)
			{
				int y = v1[x][i];
				if(w[y] > w[x])
				{
					ans -= 1ll * in[y] * out[y];
					out[y]--; in[y]++; in[x]--; out[x]++;
					ans += 1ll * in[y] * out[y];
					if(d[y] > T) v3[y].push_back(x);
				}
			}
		}
		else
		{
			for(int i = 0; i < v2[x].size(); i++)
			{
				int y = v2[x][i];
				if(w[y] > w[x])
				{
					ans -= 1ll * in[y] * out[y];
					out[y]--; in[y]++; in[x]--; out[x]++;
					ans += 1ll * in[y] * out[y];
				}
			}
			for(int i = 0; i < v3[x].size(); i++)
			{
				int y = v3[x][i];
				ans -= 1ll * in[y] * out[y];
				out[y]--; in[y]++; in[x]--; out[x]++;
				ans += 1ll * in[y] * out[y];
			}
			v3[x].clear();
		}
		w[x] = n + j;
		ans += 1ll * in[x] * out[x];
		printf("%lld\n", ans);
	}
	return 0;
}