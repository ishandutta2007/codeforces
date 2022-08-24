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
	int n;
	cin >> n;
	int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == 'U')
			++c0;
		else if (c == 'D')
			++c1;
		else if (c == 'L')
			++c2;
		else
			++c3;
	}
	cout << min(c0, c1) * 2 + min(c2, c3) * 2 << "\n";
	return 0;
}