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

int n;

int a[100000];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    cin >> n;
    int fl = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            cout << a[i] / 2 << "\n";
        } else if (fl) {
            cout << (a[i] + 1) / 2 << "\n";
            fl = 0;
        } else {
            cout << (a[i] - 1) / 2 << "\n";
            fl = 1;
        }
    }
	return 0;
}