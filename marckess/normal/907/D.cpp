#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	bool f = 0;
	vvi res;

	cin >> n >> m;

	res = vvi(n, vi(m));

	if (n == 1 && m == 1) {
		cout << "YES" << endl;
		cout << 1 << endl;
		return 0;
	}

	if (min(n, m) < 3 && max(n, m) <= 3) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	if (n == 3 && m == 3) {
		cout << "5 3 8" << endl
			 << "1 9 4" << endl
			 << "7 2 6" << endl;
		return 0;
	}

	if (n == 2 && m == 4) {
		cout << "5 4 7 2" << endl
			 << "3 6 1 8" << endl;
		return 0;
	}

	stack<int> x, y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i % 2 == j % 2) {
				x.push((i-1) * m + j);
			} else {
				y.push((i-1) * m + j);
			}
		}
	}

	if (n < m) {
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {

				if (x.size()) {
					res[i][j] = x.top();
					x.pop();
				} else {
					res[i][j] = y.top();
					y.pop();
				}

			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (x.size()) {
					res[i][j] = x.top();
					x.pop();
				} else {
					res[i][j] = y.top();
					y.pop();
				}

			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}