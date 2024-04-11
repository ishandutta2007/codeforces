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

const int N = 1200;

int n;
int a[N];
int b[N];

int get() {
	for (int i = 0; i <= n; ++i) {
		b[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		++b[a[i]];
	}
	int c = 0;
	while (b[c]) {
		++c;
	}
	return c;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int now = 0;
	while (now < n && a[now] == now) {
		++now;
	}
	vector<int> vv;
	while (now < n) {
		int x = get();
		if (x < n) {
			vv.push_back(x + 1);
			a[x] = x;
		} else {
			vv.push_back(now + 1);
			a[now] = x;
		}
		while (now < n && a[now] == now) {
			++now;
		}
	}
	cout << vv.size() << "\n";
	for (int i = 0; i < vv.size(); ++i) {
		cout << vv[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}