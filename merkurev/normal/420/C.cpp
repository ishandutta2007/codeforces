#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 300500;

int deg[maxn];
pair <int, int> e[maxn];

vector <int> g[maxn];
pair <int, int> a[maxn];
int ord[maxn];
int tm = 146;
int tmer[maxn];


const int inf = 1e9;



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		deg[a]++;
		deg[b]++;
		e[i] = make_pair(a, b);
	}
	for (int i = 0; i < n; i++)
		a[i] = make_pair(deg[i], i);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		ord[a[i].second] = i;
	}
	for (int i = 0; i < n; i++)
	{
		int a = ord[e[i].first];
		int b = ord[e[i].second];
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		deg[i] = g[i].size();
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int need = p - deg[i];
		int pos = lower_bound(deg + i + 1, deg + n, need) - deg;
		ans += n - pos;
		//fprintf(stderr, "%d\n", pos);
		for (int j = 0; j < g[i].size(); j++)
		{
			int nv = g[i][j];
			if (nv < pos)
				continue;
			deg[nv]--;
		}
		for (int j = 0; j < g[i].size(); j++)
		{
			int nv = g[i][j];
			if (tmer[nv] == tm)
				continue;
			tmer[nv] = tm;
			if (nv < pos)
				continue;
			if (deg[nv] < need)
				ans--;
		}
		tm++;
		for (int j = 0; j < g[i].size(); j++)
		{
			int nv = g[i][j];
			if (nv < pos)
				continue;
			deg[nv]++;
		}
	}
	printf("%I64d\n", ans);


	return 0;
}