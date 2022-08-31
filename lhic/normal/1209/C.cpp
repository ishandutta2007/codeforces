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

const int N = 2e5 + 100;

int n;
string s;

int a[N];

int lst[10];
int fs[10];

int cl[N];

void solve() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
	}
	for (int i = 0; i < 10; ++i) {
		fs[i] = n, lst[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		fs[a[i]] = min(fs[a[i]], i);
		lst[a[i]] = max(lst[a[i]], i);
	}
	fill(cl, cl + n, 0);
	int cur = 0;
	for (int i = 0; i < 10; ++i) {
		if (lst[i] == -1) {
			continue;
		}
		while (cur <= lst[i]) {
			if (a[cur] == i) {
				cl[cur] = 1;
			}
			++cur;
		}
		if (!cl[fs[i]]) {
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		fs[i] = n, lst[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		if (cl[i] == 0) {
			fs[a[i]] = min(fs[a[i]], i);
			lst[a[i]] = max(lst[a[i]], i);
		}
	}
	cur = 0;
	for (int i = 0; i < 10; ++i) {
		if (lst[i] == -1) {
			continue;
		}
		while (cur <= lst[i]) {
			if (a[cur] == i) {
				cl[cur] = 2;
			}
			++cur;
		}
		if (!cl[fs[i]]) {
			cout << "-\n";
			return;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << cl[i];
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