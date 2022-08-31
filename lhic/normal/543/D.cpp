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


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 300000;
const ll MOD = 1000000007;

ll ans[MAXN];
ll dp[MAXN];
int n;
vector<int> eds[MAXN];
vector<ll> pr[MAXN];


void dfs0(int v) {
	dp[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		dfs0(u);
		dp[v] = (dp[v] * (dp[u] + 1)) % MOD;
	}
}

void dfs(int v, ll up) {
//	cout << v << " " << up << "\n";
	ans[v] = up;
	pr[v].resize(eds[v].size());
	if (!eds[v].empty())
		pr[v].back() = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		ans[v] = (ans[v] * (dp[u] + 1)) % MOD;
	}
	for (int i = (int)eds[v].size() - 1; i > 0; --i)
		pr[v][i - 1] = (pr[v][i] * (dp[eds[v][i]] + 1)) % MOD;
	ll xx = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		dfs(u, (((up * xx) % MOD) * pr[v][i] + 1) % MOD);
		xx = (xx * (dp[u] + 1)) % MOD;
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		eds[x].push_back(i);
	}
	dfs0(0);
//	for (int i = 0; i < n; ++i)
//		cout << dp[i] << " ";
//	cout << "\n";
	dfs(0, 1);
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	return 0;
}