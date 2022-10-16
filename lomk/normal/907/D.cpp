/*input
10 1000
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 100005
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}

int n, m;
vector<vector<int> > a;
random_device rd;
pair<int, int> loc[N];
int tmp[N];

void shufRow(int i) {
	for (int j = 1; j <= m; j++) {
		tmp[j] = a[i][j];
	}
	shuffle(tmp + 1, tmp + m + 1, rd);
	for (int j = 1; j <= m; j++) {
		a[i][j] = tmp[j];
	}
}

void shufCol(int j) {
	for (int i = 1; i <= n; i++) tmp[i] = a[i][j];
	shuffle(tmp + 1, tmp + n + 1, rd);
	for (int i = 1; i <= n; i++) a[i][j] = tmp[i];
}

void ch(int i, int j) {
	int x = rd() % n + 1; int y = rd() % m + 1;
	if (x != 1)
		while (x == i) x = rd() % n + 1;
	if (y != 1)
		while (y == j) y = rd() % m + 1;
	swap(a[x][y], a[i][j]);
}

bool check() {
	bool ret = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j != m) {
				if (loc[a[i][j]].fi == loc[a[i][j + 1]].fi && abs(loc[a[i][j]].se - loc[a[i][j + 1]].se) == 1) {
					ch(i, j); ret = false;
				}
				if (loc[a[i][j]].se == loc[a[i][j + 1]].se && abs(loc[a[i][j]].fi - loc[a[i][j + 1]].fi) == 1) {
					ch(i, j); ret = false;
				}
			}
			if (i != n) {
				if (loc[a[i][j]].fi == loc[a[i + 1][j]].fi && abs(loc[a[i][j]].se - loc[a[i + 1][j]].se) == 1) {
					ch(i, j); ret = false;
				}
				if (loc[a[i][j]].se == loc[a[i + 1][j]].se && abs(loc[a[i][j]].fi - loc[a[i + 1][j]].fi) == 1) {
					ch(i, j); ret = false;
				}
			}
		}
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	a.assign(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = (i - 1) * m + j, loc[a[i][j]] = mp(i, j);
	for (int i = 1; i <= n; i++)
		shufRow(i);
	for (int j = 1; j <= m; j++)
		shufCol(j);
	for (int i = 1; i <= 500; i++) {
		if (check()) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					cout << a[i][j] << sp;
				}
				cout << endl;
			}
			exit(0);
		}
	}
	cout << "NO" << endl;
}