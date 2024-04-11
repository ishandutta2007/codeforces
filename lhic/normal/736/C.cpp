#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 120;
const ll MOD = 1e9 + 7;
int was[MAXN];
ll dp[120][22][22];
vector<int> eds[MAXN];
int n, k;

void dfs1(int v) {
	was[v] = 1;
	int pr = -1;
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u);
		else
			pr = u;
	}
	ll now = 1;
	for (int u: eds[v]) {
		if (u == pr)
			continue;
		ll sum = 0;
		for (int i = 0; i <= k; ++i)
			sum = (sum + dp[u][i][k]) % MOD;
		now = (now * sum) % MOD;
	}
	for (int i = 0; i <= k; ++i)
		dp[v][k][i] = now;
	for (int i = 1; i < k; ++i) {
		for (int j = 0; j <= k; ++j) {
			ll n1 = 1;
			ll n2 = 0;
			for (int u: eds[v]) {
				if (u == pr)
					continue;
				ll sum = 0;
				for (int l = 0; l <= i; ++l)
					sum = (sum + dp[u][l][max(i, j - 1)]) % MOD;
				ll oth = dp[u][i + 1][max(0, j - 1)];
				n2 = (n2 * (sum + oth) + n1 * oth) % MOD;
				n1 = (n1 * sum) % MOD;
			}
			dp[v][i][j] = n2;
		}
	}
	for (int j = 0; j <= k; ++j) {
		ll n1 = 0, n2 = 0;
		if (j == 0)
			n1 = 1;
		else
			n2 = 1;
		for (int u: eds[v]) {
			if (u == pr)
				continue;
			ll a = dp[u][0][max(0, j - 1)];
			ll b = dp[u][1][max(0, j - 1)];
			n2 = (n2 * (a + b) + n1 * b) % MOD;
			n1 = (n1 * a) % MOD;
		}
		dp[v][0][j] = n2;
	}
}


int main() {
	cin >> n >> k;
	if (k == 0) {
		cout << 1 << "\n";
		return 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	ll ans = 0;
	for (int j = 0; j <= k; ++j)
		ans = (ans + dp[0][j][0]) % MOD;
	cout << ans << "\n";
	return 0;
}