#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, m, res;
int mx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int my[] = {1, 0, -1, 1, -1, 1, 0, -1};
vector<vector<char>> a, b;
vvi d, dis;

bool valid (int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

bool esPos (int x) {
	b = a;
	queue<int> qx, qy;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'X' && dis[i][j] < x)
				b[i][j] = '.';
			if (b[i][j] == 'X') 
				qx.push(i), qy.push(j);
		}

	for (int kk = 0; kk < x; kk++) {
		queue<int> ax, ay;

		while (qx.size()) {
			int i = qx.front(), j = qy.front();
			qx.pop(), qy.pop();

			for (int k = 0; k < 8; k++) {
				int x = i + mx[k], y = j + my[k];
				if (valid(x, y) && b[x][y] == '.') {
					b[x][y] = 'X';
					ax.push(x), ay.push(y);
				}
			}
		}

		qx = ax, qy = ay;
	}

	/*cout << x << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << b[i][j];
		cout << endl;
	}*/

	return a == b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	a = vector<vector<char>>(n, vector<char>(m));
	d = vvi(n, vi(m));
	dis = vvi(n, vi(m, -1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	queue<int> qx, qy;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (valid(i, j) && a[i][j] == 'X') {
				for (int k = 0; k < 8; k++) {
					int x = i + mx[k], y = j + my[k];
					d[i][j] += valid(x, y) && a[x][y] == 'X';
				}

				if (d[i][j] < 8) {
					dis[i][j] = 0;
					qx.push(i), qy.push(j);
				}
			}

	while (qx.size()) {
		int i = qx.front(), j = qy.front();
		qx.pop(), qy.pop();

		for (int k = 0; k < 8; k++) {
			int x = i+mx[k], y = j+my[k];
			if (valid(x, y) && dis[x][y] == -1) {
				dis[x][y] = dis[i][j] + 1;
				qx.push(x), qy.push(y);
			}
		}
	}

	int i = 0, j = max(n, m), rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}

	res = i;
	cout << res << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.' || dis[i][j] < res)
				cout << '.';
			else
				cout << 'X';
		}
		cout << endl;
	}

	return 0;
}