#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n, x, y;
vector <int> neigh[Maxn];
int dp1[Maxn], dp2[Maxn];

bool Has(int v, int p, int t, int dp[])
{
	if (v == t) { dp[v] = 0; return true; }
	dp[v] = 1;
	bool res = false;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (!Has(u, v, t, dp)) dp[v] += dp[u];
		else res = true;
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Has(x, 0, y, dp1); Has(y, 0, x, dp2);
	ll ways = ll(n) * (n - 1) - ll(dp1[x]) * dp2[y];
	cout << ways << endl;
	return 0;
}