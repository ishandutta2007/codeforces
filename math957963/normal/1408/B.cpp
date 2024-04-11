#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define N 500010
#define MOD 998244353



int main() {
	int n, k, t;
	int x, y, z;
	cin >> t;
	rep(tt, t) {
		cin >> n >> k;
		cin >> x;
		z = 0;
		rep(i, n-1) {
			cin >> y;
			if (x < y)z++;
			x = y;
		}
		if (k == 1) {
			if (z == 0)cout << 1 << endl;
			else cout << -1 << endl;
		}
		else {
			k--;
			if (z == 0)cout << 1 << endl;
			else cout << (z + k - 1) / k << endl;
		}
	}

	return 0;
}