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

const int N = 210000;


int n;
int a[N];

int used[N];
int b[N];
int rv[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	fill(b, b + n, -1);
	fill(used, used + n, 0);
	vector<int> out;
	vector<int> in;
	int ans0 = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[a[i]]) {
			b[i] = a[i];
			used[a[i]] = 1;
			++ans0;
		} else {
			out.push_back(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			in.push_back(i);
		}
	}
	sort(ALL(in));
	sort(ALL(out));
	reverse(ALL(out));
	assert(in.size() == out.size());
	for (int i = 0; i < in.size(); ++i) {
		b[out[i]] = in[i];
	}
	for (int i = 0; i < n; ++i) {
		rv[b[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		if (b[i] == i) {
			b[i] = a[i];
			int x = rv[a[i]];
			b[x] = i;
			rv[i] = x;
			rv[a[i]] = i;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) {
			++ans;
		}
	}
	assert(ans == ans0);
	cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		cout << b[i] + 1 << " ";
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