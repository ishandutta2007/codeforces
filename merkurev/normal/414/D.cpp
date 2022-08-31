#include <iostream>
#include <vector>
using namespace std;


const int maxn = 1e5 + 100;
vector <int> g[maxn];

int cnt[maxn];
int taked[maxn];

void dfs(int v, int par, int level)
{
	cnt[level]++;
	for (int i = 0; i < g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == par)
			continue;
		dfs(nv, v, level + 1);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m, k, p;
	scanf("%d%d%d", &m, &k, &p);
	if (k == 0)
	{
		printf("0");
		return 0;
	}

	for (int i = 0; i < m - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1, 0);

	int ans = 1;
	int dlevel = m - 1;   
	int alltaked = 0;
	int cost = 0;
                     

	for (int level = m; level >= 1; level--)
	{
	//	fprintf(stderr, "level = %d, cnt = %d\n", level, cnt[level] );
		while (dlevel >= 1)
		{
			int oneCost = level - dlevel;
			int canPay = k;
			if (oneCost != 0)
				canPay = (p - cost) / oneCost;
			int rem = cnt[dlevel] - taked[dlevel];
			int need = k - alltaked;
			int take = min(canPay, min(need, rem) );

			taked[dlevel] += take;
			alltaked += take;
			cost += oneCost * take;

			if (taked[dlevel] != cnt[dlevel] )
				break;
			dlevel--;
		}
		ans = max(ans, alltaked);

		alltaked -= taked[level];
		cost -= alltaked;
	}



	printf("%d\n", ans);

	return 0;
}