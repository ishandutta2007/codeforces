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
	int n;
	cin >> n;
	vector<vector<int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j <= n; j++) {
				a[j].push_back((i - 1) * n + j);
			}
		} else {
			for (int j = 1; j <= n; j++) {
				a[n - j + 1].push_back((i - 1) * n + j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int& i : a[i]) {
			cout << i << ' ';
		}
		cout << endl;
	}
    return 0;
}