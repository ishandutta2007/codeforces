#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 60
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
	int t, n, m;
	char a[N][N];
	bool c[2][2];
	cin >> t;
	rep(tt, t) {
		cin >> n >> m;
		rep(i, N)rep(j, N)a[i][j] = 0;
		rep(i, n)cin >> a[i];
		rep(i, 2)rep(j, 2)c[i][j] = false;
		rep(i, n) {
			rep(j, m) {
				if (a[i][j] == 'R') {
					if ((i + j) % 2 == 0)c[0][0] = true;
					if ((i + j) % 2 == 1)c[1][0] = true;
				}
				if (a[i][j] == 'W') {
					if ((i + j) % 2 == 0)c[0][1] = true;
					if ((i + j) % 2 == 1)c[1][1] = true;
				}
			}
		}
		if ((!c[0][0]) && (!c[1][1])) {
			rep(i, n) {
				rep(j, m) {
					if ((i + j) % 2 == 0)a[i][j] = 'W';
					if ((i + j) % 2 == 1)a[i][j] = 'R';
				}
			}
			cout << "YES" << endl;
			rep(i, n)cout << a[i] << endl;
		}
		else if ((!c[1][0]) && (!c[0][1])) {
			rep(i, n) {
				rep(j, m) {
					if ((i + j) % 2 == 0)a[i][j] = 'R';
					if ((i + j) % 2 == 1)a[i][j] = 'W';
				}
			}
			cout << "YES" << endl;
			rep(i, n)cout << a[i] << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}