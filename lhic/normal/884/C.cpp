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
vector<ll> vv;
int p[120000];
int was[120000];
int n;


int cc = 0;

void dfs1(int v) {
	++cc;
	was[v] = 1;
	if (was[p[v]])
		return;
	dfs1(p[v]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		--p[i];
	}
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		cc = 0;
		dfs1(i);
		vv.push_back(cc);
	}
	sort(vv.rbegin(), vv.rend());
	ll ans = 0;
	if (vv.size() == 1) {
		ans = vv[0] * vv[0];
	}
	else {
		ans = (vv[0] + vv[1]) * (vv[0] + vv[1]);
		for (int i = 2; i < vv.size(); ++i)
			ans += vv[i] * vv[i];
	}
	cout << ans << "\n";
	return 0;
}