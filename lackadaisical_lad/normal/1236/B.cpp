//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

ll binpow(ll a, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			(res *= a) %= mod;
		}
		(a *= a) %= mod;
		p >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	ll res = binpow(2, m) - 1 + mod;
	cout << binpow(res % mod, n);
    return 0;
}