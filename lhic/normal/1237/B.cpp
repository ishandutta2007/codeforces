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

const int N = 120000;

int n;
int a[N];
int b[N];
int pos[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        b[i] = pos[b[i]];
    }

    int mx = n;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        mx = min(mx, b[i]);
        if (mx < b[i]) {
            ++ans;
        }
    }

    cout << ans << "\n";
	return 0;
}