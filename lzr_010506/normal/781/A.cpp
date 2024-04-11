#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 100;

int n;
vector<int> mp[N];
int ans[N], k;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs(int u, int p)
{
	int cnt = 0;
	for (int i = 0; i < mp[u].size(); i ++)
	{
		int v = mp[u][i];
		if (v == p) continue;
		cnt ++;
		while (cnt == ans[u] || cnt == ans[p]) cnt ++;
		ans[v] = cnt;
		dfs(v, u);
		k = max(k, cnt);
	}
}

int main()
{
	n = read();
	int u, v;
	for (int i = 0; i < n - 1; i ++)
	{
		u = read();
		v = read();
		mp[u].pb(v);
		mp[v].pb(u);
	}

	ans[1] = 1, k = 1;
	dfs(1,0);

	printf("%d\n", k);
	for (int i = 1; i <= n; i ++)
		printf("%d ", ans[i]);

	return 0;
}