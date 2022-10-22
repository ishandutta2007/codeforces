#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
const int mod = 998244353;

int n, k;
vector <int> neigh[Maxn];
int cnt[Maxn];
int dp[Maxn][Maxn];
int res;

void Solve(int v, int p)
{
	cnt[v] = 1;
	dp[v][0] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v);
		for (int j = cnt[v] - 1; j >= 0; j--) {
			int add = dp[v][j]; dp[v][j] = 0;
			for (int l = 0; l < cnt[u]; l++) {
				dp[v][j] = (dp[v][j] + ll(add) * dp[u][l]) % mod;
				if (j + l + 1 <= k)
					dp[v][max(j, l + 1)] = (dp[v][max(j, l + 1)] + ll(add) * dp[u][l]) % mod;
			}
		}
		cnt[v] += cnt[u];
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Solve(1, 0);
	for (int i = 0; i <= k; i++)
		res = (res + dp[1][i]) % mod;
	printf("%d\n", res);
    return 0;
}