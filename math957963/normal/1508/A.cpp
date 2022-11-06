#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
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
	int n, t;
	int c[3][2];
	int cc[3];
	int ccc;
	int d[N];
	bool v;
	bool cv;
	char ans[N];
	char a[3][N];
	char b[2][N];
	int itr[2];
	int itrr;
	int cnt;
	rep(i, N) {
		rep(j, 3)a[j][i] = 0;
		ans[i] = 0;
	}
	cin >> t;
	rep(tt, t) {
		v = false;
		rep(i, 3)rep(j, 2)c[i][j] = 0;
		cin >> n;
		ccc = 0;
		rep(i, 3) {
			cin >> a[i];
			rep(j, 2 * n) {
				if (a[i][j] == '0')c[i][0]++;
				else c[i][1]++;
			}
			if (c[i][0] < c[i][1]) {
				cc[i] = 0;
				ccc++;
			}
			else cc[i] = 1;
		}
		if (ccc >= 2) {
			v = true;
			rep(i, 3) {
				rep(j, 2 * n) {
					if (a[i][j] == '1')a[i][j] = '0';
					else a[i][j] = '1';
				}
				cc[i] = 1 - cc[i];
			}
		}
		if ((cc[0] == 1) && (cc[1] == 1)) {
			rep(j, 2 * n) {
				b[0][j] = a[0][j];
				b[1][j] = a[1][j];
			}
		}
		else if ((cc[0] == 1) && (cc[2] == 1)) {
			rep(j, 2 * n) {
				b[0][j] = a[0][j];
				b[1][j] = a[2][j];
			}
		}
		else if ((cc[1] == 1) && (cc[2] == 1)) {
			rep(j, 2 * n) {
				b[0][j] = a[1][j];
				b[1][j] = a[2][j];
			}
		}
		itr[0] = 0;
		itr[1] = 0;
		itrr = 0;
		while (true) {
			if ((itr[0] >= (2 * n)) && (itr[1] >= (2 * n))) {
				while (itrr < (3 * n)) {
					ans[itrr] = '0';
					itrr++;
				}
				break;
			}
			if (itr[0] >= (2 * n)) {
				while (itr[1] < (2 * n)) {
					ans[itrr] = b[1][itr[1]];
					itr[1]++;
					itrr++;
				}
				while (itrr < (3 * n)) {
					ans[itrr] = '0';
					itrr++;
				}
				break;
			}
			if (itr[1] >= (2 * n)) {
				while (itr[0] < (2 * n)) {
					ans[itrr] = b[0][itr[0]];
					itr[0]++;
					itrr++;
				}
				while (itrr < (3 * n)) {
					ans[itrr] = '0';
					itrr++;
				}
				break;
			}
			if ((b[0][itr[0]] == '1') || (b[1][itr[1]] == '1')) {
				ans[itrr] = '1';
				itrr++;
				if (b[0][itr[0]] == '1')itr[0]++;
				if (b[1][itr[1]] == '1')itr[1]++;
			}
			else {
				ans[itrr] = '0';
				itrr++;
				itr[0]++;
				itr[1]++;
			}
		}
		if (v) {
			rep(i, 3 * n) {
				if (ans[i] == '0')ans[i] = '1';
				else ans[i] = '0';
			}
		}
		cout << ans << endl;
		rep(i, 2*n + 1) {
			rep(j, 3) {
				a[j][i] = 0;
			}
		}
		rep(i, 3 * n + 1)ans[i] = 0;
	}
	return 0;
}