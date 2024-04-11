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

int n, t;
int main() {
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		a = 86400 - a;
		t -= a;
		if (t <= 0) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	return 0;
}