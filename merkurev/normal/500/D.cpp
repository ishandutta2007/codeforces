#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;



const int maxn = 1e5 + 100;
vector <int> g[maxn];
long long cnt[maxn];
double ans = 0;
int n;
int e[maxn][2];
int ec[maxn];

int cntv[maxn];
int dfs(int v, int par)
{
	cntv[v] = 1;
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int eid = g[v][i];
		int nv = e[eid][0] + e[eid][1] - v;
		if (nv == par)
			continue;
		cntv[v] += dfs(nv, v);
		cnt[eid] = cntv[nv] * 1LL * (n - cntv[nv] );
	}
	return cntv[v];
}


int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d%d", &e[i][0], &e[i][1], &ec[i] );
		e[i][0]--;
		e[i][1]--;
		g[e[i][0] ].push_back(i);
		g[e[i][1] ].push_back(i);
	}
	
	dfs(0, -1);
	long long cntAll = n * 1LL * (n - 1) / 2;
	for (int i = 0; i < n - 1; i++)
	{
		ans += 3. * (double) cnt[i] / (double) cntAll * (double) ec[i];
	}

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		int d = ec[a] - b;
		ec[a] = b;
		ans -= 3. * (double) cnt[a] / (double) cntAll * (double) d;
		printf("%.10lf\n", ans);
	}



	return 0;
}