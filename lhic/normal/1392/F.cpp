#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 1e6 + 100;

int n;
ll hh[N];
ll a[N];
ll up[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> hh[i];
	}

	ll st = hh[0];
	vector<int> vv;
	ll ad = 0;

	for (int i = 0; i + 1 < n; ++i) {
		ll g = hh[i + 1] - hh[i] - 1 + ad;
		ad = 0;
		while (!vv.empty() && g) {
			if (g >= i + 1 - vv.back()) {
				g -= (i + 1) - vv.back();
				ad += i - vv.back();
				vv.pop_back();
			} else {
				vv.back() += g;
				ad += g;
				g = 0;
			}
		}
		
		if (g) {
			ll k = g / (i + 2);
			st += k;
			ad += k * (i + 1);
			g %= (i + 2);
			if (g) {
				vv.push_back(g - 1);
				ad += g;
				st += 1;
				g = 0;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		up[i] = 1;
	}
	for (int i : vv) {
		up[i] = 0;
	}

	hh[0] = st;
	for (int i = 1; i < n; ++i) {
		hh[i] = hh[i - 1] + up[i - 1];
	}

	for (int i = 0; i < n; ++i) {
		cout << hh[i] << " ";
	}
	cout << "\n";

	return 0;
}