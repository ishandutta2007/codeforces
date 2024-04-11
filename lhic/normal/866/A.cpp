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
	int a;
	cin >> a;
	if (a == 1) {
		cout << 1 << " " << 1 << "\n";
		cout << 1 << "\n";
	}
	else {
		cout << 2 * (a - 1) << " " << 2 << "\n";
		cout << 1 << " " << 2 << "\n";
	}
	return 0;
}