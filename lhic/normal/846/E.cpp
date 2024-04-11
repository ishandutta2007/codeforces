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
const ll INF = 1e18;
ll a[120000];
ll b[120000];
vector<pair<int, ll> > eds[120000];
int n;

ll mul(ll a, ll b) {
	if (a == 0)
		return 0;
	if (INF / a < b)
		return INF;
	return a * b;
}

ll dfs1(int v) {
	ll hv = b[v];
	ll nd = a[v];
	for (auto e: eds[v]) {
		ll x = dfs1(e.first);
		if (x < 0) {
			nd = min(INF, nd + mul(-x, e.second));
		}
		else {
			hv += x;
		}
	}
	return hv - nd;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", b + i);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 1; i < n; ++i) {
		int x;
		ll k;
		scanf("%d%lld", &x, &k);
		--x;
		eds[x].push_back(make_pair(i, k));
	}
	ll ans = dfs1(0);
	if (ans < 0)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}