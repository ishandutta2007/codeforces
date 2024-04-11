#ifndef BZ
#ifndef __clang__
#pragma GCC optimize "-O3"
#endif
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


const int MAXN = 220000;
int cnt;
ll a[MAXN];
ll n, m;

pair<int, int> get(ll x) {
	--x;
	return make_pair(x / m, x % m);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> cnt;
	for (int i = 0; i < cnt; ++i) {
		cin >> a[i];
	}
	n = 1e9;
	m = 1e9;
	for (int i = 0; i < cnt - 1; ++i) {
		if (abs(a[i] - a[i + 1]) != 1) {
			m = abs(a[i] - a[i + 1]);
		}
	}
	if (m == 0) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < cnt - 1; ++i) {
		auto x1 = get(a[i]);
		auto x2 = get(a[i + 1]);
		if (abs(x1.first - x2.first) + abs(x1.second - x2.second) != 1) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	cout << n << " " << m << "\n";
	return 0;
}