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

int a[510][510];
int b[510][510];

int c[510][510];
int d[510][510];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (k % 2 == 0)k /= 2;
	else k = 0;
	rep(i, 510) {
		rep(j, 510) {
			a[i][j] = 100000000;
			b[i][j] = 100000000;
			c[i][j] = MOD;
			d[i][j] = MOD;
		}
	}
	rep(i, n) {
		rep(j, m - 1) {
			cin >> a[i][j + 1];
		}
	}
	rep(i, n - 1) {
		rep(j, m) {
			cin >> b[i + 1][j];
		}
	}
	rep2(i, 1, n) {
		rep2(j, 1, m)c[i][j] = 0;
	}
	rep(kk, k) {
		rep2(i, 1, n) {
			rep2(j, 1, m) {
				d[i][j] = min(d[i][j], c[i][j - 1] + a[i - 1][j - 1]);
				d[i][j] = min(d[i][j], c[i][j + 1] + a[i - 1][j]);
				d[i][j] = min(d[i][j], c[i - 1][j] + b[i - 1][j - 1]);
				d[i][j] = min(d[i][j], c[i + 1][j] + b[i][j - 1]);
			}
		}
		rep2(i, 1, n) {
			rep2(j, 1, m) {
				c[i][j] = d[i][j];
				d[i][j] = MOD;
			}
		}
	}
	if (k == 0) {
		rep2(i, 1, n) {
			rep2(j, 1, m) {
				c[i][j] = -1;
			}
		}
	}
	else {
		rep2(i, 1, n) {
			rep2(j, 1, m) {
				c[i][j] *= 2;
			}
		}
	}
	rep2(i, 1, n) {
		rep2(j, 1, m) {
			cout << c[i][j];
			if (j < m)cout << " ";
			else cout << endl;
		}
	}
	return 0;
}