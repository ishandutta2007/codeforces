#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
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

int main() {
	int k;
	cin >> k;
	int mx = 25;
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		mx = max(mx, a);
	}
	cout << mx - 25 << "\n";
	return 0;
}