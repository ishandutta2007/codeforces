#include <bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

int gcd(int x,int y) { return y == 0 ? x : gcd(y, x % y); }
int mul(int x,int y,int md) {
	int res = 0;
	while(y) {
		if (y & 1) res = res + x >= md ? res + x - md : res + x;
		x = x + x >= md ? x + x - md : x + x;
		y >>= 1;
	}
	return res;
}
int fpow(int x,int y,int md) {
	int res = 1;
	while(y) {
		if (y & 1) res = mul(res, x, md);
		x = mul(x, x, md);
		y >>= 1;
	}
	return res;
}
signed main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	while(n--) {
		int p, q, b; cin >> p >> q >> b;
		int div = gcd(p, q);
		p /= div, q /= div; b %= q;
		if (fpow(b, 64, q) == 0) cout << "Finite\n";
		else cout << "Infinite\n";
	}
}