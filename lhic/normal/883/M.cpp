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
	int x1, x2, y1, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	int mnx = min(x1, x2 - 1);
	int mxx = max(x1, x2 + 1);
	int mny = min(y1, y2 - 1);
	int mxy = max(y1, y2 + 1);
	cout << (mxx - mnx) * 2 + 2 * (mxy - mny) << "\n";
	return 0;
}