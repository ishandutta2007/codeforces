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
	int t;
	int a[N];
	int b[N];
	int c[N];
	int d[N];
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n) {
			cin >> a[i];
		}
		rep(i, n) {
			cin >> b[i];
		}
		rep(i, n) {
			cin >> c[i];
		}
		d[0] = a[0];
		rep(i, n - 2) {
			if (a[i + 1] == d[i])d[i + 1] = b[i + 1];
			else d[i + 1] = a[i + 1];
		}
		if ((a[n - 1] != d[0]) && (a[n - 1] != d[n - 2]))d[n - 1] = a[n - 1];
		if ((b[n - 1] != d[0]) && (b[n - 1] != d[n - 2]))d[n - 1] = b[n - 1];
		if ((c[n - 1] != d[0]) && (c[n - 1] != d[n - 2]))d[n - 1] = c[n - 1];
	rep(i, n - 1)cout << d[i] << " ";
	cout << d[n - 1] << endl;
     }
	return 0;
}