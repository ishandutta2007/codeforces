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
	int a[N];
	rep(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	cin >> n;
	rep(i, n) {
		cin >> x >> y;
		if (x <= 2)cout << 1 << endl;
		else cout << (x + (2 * y) - 3) / y << endl;

	}
	return 0;
}