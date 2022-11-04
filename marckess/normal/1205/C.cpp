#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;

int n, r;
vvi a, b;

int query (int a, int b, int c, int d) {
	int r;
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	cin >> r;
	return r;
}

bool dp (int x, int y, int s, int t, vvi &a, vvvvi &mem) {
	if (s < x || t < y) return 0;
	if (s - x + t - y == 1) return a[x][y] == a[s][t];
	int &res = mem[x][y][s][t];
	if (res != -1) return res;
	if (a[x][y] != a[s][t]) return res = 0;
	return res = 
		dp(x+1, y, s-1, t, a, mem) ||
		dp(x+1, y, s, t-1, a, mem) ||
		dp(x, y+1, s-1, t, a, mem) ||
		dp(x, y+1, s, t-1, a, mem);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	a.assign(n + 1, vi(n + 1));
	a[1][1] = 1;

	for (int i = 3; i <= n; i += 2) {
		r = query(1, i - 2, 1, i);
		if (r) a[1][i] = a[1][i-2];
		else a[1][i] = 1 - a[1][i-2];
 
		r = query(i - 2, 1, i, 1);
		if (r) a[i][1] = a[i-2][1];
		else a[i][1] = 1 - a[i-2][1];
 
		for (int j = 3; j <= n; j += 2) {
			if (i < n || j < n) {
				r = query(i, j - 2, i, j);
				if (r) a[i][j] = a[i][j-2];
				else a[i][j] = 1 - a[i][j-2];
			}
		}
	}
 
	r = query(1, 1, 2, 2);
	if (r) a[2][2] = 1;
 
	for (int i = 4; i <= n; i += 2) {
		r = query(2, i - 2, 2, i);
		if (r) a[2][i] = a[2][i-2];
		else a[2][i] = 1 - a[2][i-2];
 
		r = query(i - 2, 2, i, 2);
		if (r) a[i][2] = a[i-2][2];
		else a[i][2] = 1 - a[i-2][2];
 
		for (int j = 4; j <= n; j += 2) {
			if (i < n || j < n) {
				r = query(i, j - 2, i, j);
				if (r) a[i][j] = a[i][j-2];
				else a[i][j] = 1 - a[i][j-2];
			}
		}
	}
 
	b = a;
	b[1][2] = 1;

	for (int i = 3; i <= n; i += 2) {
		r = query(i - 2, 2, i, 2);
		if (r) a[i][2] = a[i-2][2], b[i][2] = b[i-2][2];
		else a[i][2] = 1 - a[i-2][2], b[i][2] = 1 - b[i-2][2];
	}
 
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			r = query(i, 1, i + 1, 2);
			if (r) a[i][1] = a[i+1][2], b[i][1] = b[i+1][2];
			else a[i][1] = 1 - a[i+1][2], b[i][1] = 1 - b[i+1][2];
		}

		for (int j = 3 + i % 2; j <= n; j += 2) {
			r = query(i, j - 2, i, j);
			if (r) a[i][j] = a[i][j-2], b[i][j] = b[i][j-2];
			else a[i][j] = 1 - a[i][j-2], b[i][j] = 1 - b[i][j-2];
		}
	}
 
	vvvvi mema(n + 1, vvvi(n + 1, vvi(n + 1, vi(n + 1, -1))));
	vvvvi memb = mema;

	forr(x, 1, n) forr(y, 1, n) forr(s, x, n) forr(t, y, n) {
		int d = s - x + t - y;
		if (2 <= d && d % 2) {
			if (dp(x, y, s, t, a, mema) != dp(x, y, s, t, b, memb)) {
				int r = query(x, y, s, t);
				if (r == dp(x, y, s, t, b, memb)) a = b;
				x = y = s = t = n + 1;
			}
		}
	}
 
	cout << "!" << endl;
	forn(i, n) {
		forn (j, n) cout << a[i+1][j+1];
		cout << endl;
	}
 
	return 0;
}