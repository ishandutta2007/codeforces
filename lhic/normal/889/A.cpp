#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int dp0[210000];
int dp1[210000];
vector<int> eds[210000];
int n;

int dfs1(int v) {
	int ans = 1;
	for (int u: eds[v]) {
		ans += dfs1(u);
	}
	if (eds[v].size())
		--ans;
	return ans;
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		eds[p].push_back(i);
	}
	cout << dfs1(0) << "\n";
	return 0;
}