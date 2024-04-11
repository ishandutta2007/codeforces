#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int t;
	int n, m;
	char a[25][25];
	cin >> t;
	rep(tt, t) {
		cin >> n >> m;
		rep(i, 25) {
			rep(j, 25)a[i][j] = 0;
		}
		rep(i, n) {
			rep(j, m)a[i][j] = '0';
		}
		rep(i, n)if (i % 2 == 0)a[i][0] = '1';
		rep(j, m)if (j % 2 == 0)a[0][j] = '1';
		rep2(i, 2, n - 1)if (i % 2 == 0)a[i][m - 1] = '1';
		rep2(j, 2, m - 3)if (j % 2 == 0)a[n - 1][j] = '1';
		rep(i, n)cout << a[i] << endl;
	}
	return 0;
}