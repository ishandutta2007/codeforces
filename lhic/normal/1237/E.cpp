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

const int MX = 1e6 + 100;

int cc[MX + 10];

void add(int x) {
    ++cc[x];
    ++cc[x + 1];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    ll l = 0;
    ll r = 0;
    while (l + r < MX) {
        add(l + r + 1);
        if (l == r) {
            l = l * 2 + 1;
            r = r * 2 + 2;
        } else {
            l = r = r * 2;
        }
    }
    int n;
    cin >> n;
    cout << cc[n] << "\n";
	return 0;
}