#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
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


int main() {
	int n, m, k, t, z,zz;
	vector<int>x[3], y[3];
	char b[110][110];
	int a[110][110];
	rep(i, 110) {
		rep(j, 110) {
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	cin >> t;
	rep(tt, t) {
		cin >> n >> m;
		rep(i, n) {
			cin >> b[i];
		}
		rep(i, n) {
			rep(j, m) {
				if (b[i][j] == '1')a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		rep(i, n - 2) {
			z = 0;
			while (true) {
				if (z >= m)break;
				if ((z + 1) == m)z--;
				if ((a[i][z] == 1) && (a[i][z + 1] == 1)) {
					x[0].pb(i);
					y[0].pb(z);
					x[1].pb(i);
					y[1].pb(z + 1);
					x[2].pb(i + 1);
					y[2].pb(z);
					a[i][z] ^= 1;
					a[i][z + 1] ^= 1;
					a[i + 1][z] ^= 1;
				}
				else if ((a[i][z] == 1) && (a[i][z + 1] == 0)) {
					x[0].pb(i);
					y[0].pb(z);
					x[1].pb(i + 1);
					y[1].pb(z);
					x[2].pb(i + 1);
					y[2].pb(z + 1);
					a[i][z] ^= 1;
					a[i + 1][z] ^= 1;
					a[i + 1][z + 1] ^= 1;
				}
				else if ((a[i][z] == 0) && (a[i][z + 1] == 1)) {
					x[0].pb(i);
					y[0].pb(z + 1);
					x[1].pb(i + 1);
					y[1].pb(z);
					x[2].pb(i + 1);
					y[2].pb(z + 1);
					a[i][z + 1] ^= 1;
					a[i + 1][z] ^= 1;
					a[i + 1][z + 1] ^= 1;
				}
				z += 2;
			}
		}
		z = 0;
		int s;
		int c[2][2];
		while (true) {
			if (z + 3 <= m) {
				if ((a[n-2][z] == 1) && (a[n-1][z] == 1)) {
					x[0].pb(n - 2);
					y[0].pb(z);
					x[1].pb(n - 1);
					y[1].pb(z);
					x[2].pb(n - 1);
					y[2].pb(z + 1);
					a[n - 2][z] ^= 1;
					a[n - 1][z] ^= 1;
					a[n - 1][z + 1] ^= 1;
				}
				else if ((a[n - 2][z] == 1) && (a[n - 1][z] == 0)) {
					x[0].pb(n - 2);
					y[0].pb(z);
					x[1].pb(n - 2);
					y[1].pb(z + 1);
					x[2].pb(n - 1);
					y[2].pb(z + 1);
					a[n - 2][z] ^= 1;
					a[n - 2][z + 1] ^= 1;
					a[n - 1][z + 1] ^= 1;
				}
				else if ((a[n - 2][z] == 0) && (a[n - 1][z] == 1)) {
					x[0].pb(n - 1);
					y[0].pb(z);
					x[1].pb(n - 2);
					y[1].pb(z + 1);
					x[2].pb(n - 1);
					y[2].pb(z + 1);
					a[n - 1][z] ^= 1;
					a[n - 2][z + 1] ^= 1;
					a[n - 1][z + 1] ^= 1;
				}
				z++;
			}
			else {
				while (true) {
					s = 0;
					rep(i, 2) {
						rep(j, 2) {
							if (a[n - 2 + i][z + j] == 1)s++;
						}
					}
					if (s == 0)break;
					else if (s == 2) {
						k = 0;
						rep(i, 2)rep(j, 2)c[i][j] = 0;
						rep(i, 2) {
							rep(j, 2) {
								if ((k < 3) && (a[n - 2 + i][z + j] == 0)) {
									x[k].pb(n - 2 + i);
									y[k].pb(z + j);
									c[i][j] = 1;
									k++;
								}
							}
						}
						rep(i, 2) {
							rep(j, 2) {
								if ((k < 3) && (a[n - 2 + i][z + j] == 1)) {
									x[k].pb(n - 2 + i);
									y[k].pb(z + j);
									c[i][j] = 1;
									k++;
								}
							}
						}
						rep(i, 2)rep(j, 2)a[n - 2 + i][z + j] ^= c[i][j];
					}
					else {
						k = 0;
						rep(i, 2)rep(j, 2)c[i][j] = 0;
						rep(i, 2) {
							rep(j, 2) {
								if ((k < 3) && (a[n - 2 + i][z + j] == 1)) {
									x[k].pb(n - 2 + i);
									y[k].pb(z + j);
									c[i][j] = 1;
									k++;
								}
							}
						}
						rep(i, 2) {
							rep(j, 2) {
								if ((k < 3) && (a[n - 2 + i][z + j] == 0)) {
									x[k].pb(n - 2 + i);
									y[k].pb(z + j);
									c[i][j] = 1;
									k++;
								}
							}
						}
						rep(i, 2)rep(j, 2)a[n - 2 + i][z + j] ^= c[i][j];
					}

				}
				break;
			}
		}
		k = x[0].size();
		cout << k << endl;
		rep(i, k)cout << x[0][i] + 1 << " " << y[0][i] + 1 << " " << x[1][i] + 1 << " " << y[1][i] + 1 << " " << x[2][i] + 1 << " " << y[2][i] + 1 << endl;


		rep(i, n + 1) {
			rep(j, m + 1) {
				a[i][j] = 0;
				b[i][j] = 0;
			}
		}
		rep(i, 3) {
			x[i].clear();
			y[i].clear();
		}

	}


	return 0;
}