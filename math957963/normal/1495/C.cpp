#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define EPS (long double)0.000001
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
	char a[510][510];
	rep(i, 510)rep(j, 510)a[i][j] = 0;
	cin >> t;
	rep(tt, t) {
		cin >> n >> m;
		rep(i, n)cin >> a[i];
		if (m == 1) {
			rep(i, n)a[i][0] = 'X';
			rep(i, n)cout << a[i] << endl;
		}
		else {
			if (n % 3 == 0) {
				rep(i, n) {
					if (i % 3 == 1) {
						rep(j, m)a[i][j] = 'X';
					}
					else if (i % 3 == 2) {
						if ((i + 1) < n) {
							if ((a[i][1] == 'X') || (a[i + 1][1] == 'X')) {
								a[i][1] = 'X';
								a[i + 1][1] = 'X';
							}
							else {
								a[i][0] = 'X';
								a[i + 1][0] = 'X';
							}
						}
					}
				}
			}
			else {
				rep(i, n) {
					if (i % 3 == 0) {
						rep(j, m)a[i][j] = 'X';
					}
					else if (i % 3 == 1) {
						if ((i + 1) < n) {
							if ((a[i][1] == 'X') || (a[i + 1][1] == 'X')) {
								a[i][1] = 'X';
								a[i + 1][1] = 'X';
							}
							else {
								a[i][0] = 'X';
								a[i + 1][0] = 'X';
							}
						}
					}
				}
			}
			rep(i, n)cout << a[i] << endl;
		}


		rep(i, n + 1)rep(j, m + 1)a[i][j] = 0;
	}

	return 0;
}