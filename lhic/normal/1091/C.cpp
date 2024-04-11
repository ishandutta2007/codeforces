#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
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

vector<ll> ans;
ll n;

void add(ll x) {
	ll k = n / x;
	ans.push_back((2 + (k - 1) * x) * k / 2);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (ll i = 1; i * i <= n; ++i)
		if (n % i == 0)
			add(i), add(n / i);
	sort(ans.begin(), ans.end());
	ans.resize(unique(ALL(ans)) - ans.begin());
	for (ll x: ans)
		cout << x << " ";
	cout << "\n";
	return 0;
}