#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

ll sum;
int n;
int r;
ll a[1 << 18];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(10);
	cin >> n >> r;
	for (int i = 0; i < (1 << n); ++i)
		cin >> a[i], sum += a[i];
	cout << ld(sum) / (1 << n) << "\n";
	for (int i = 0; i < r; ++i) {
		int x;
		ll y;
		cin >> x >> y;
		sum -= a[x];
		a[x] = y;
		sum += a[x];
		cout << ld(sum) / (1 << n) << "\n";
	}
	return 0;
}