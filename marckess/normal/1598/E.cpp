
// Problem : E. Staircases
// Contest : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1598/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, q, a[MX][MX];
ll res;

void upd (int x, int y, int f, int k) {
	int cn = 0;
	while (x <= n && y <= m) {
		if (a[x][y]) cn = 0;
		else cn++;
		
		res += k * cn;
				
		if (f) x++;
		else y++;
		f ^= 1;
	}
}

void upd (int x, int y, int k) {
	int f = 0, xx = x, yy = y;
	while (x > 0 && y > 0) {
		if (f) y--;
		else x--;
		f ^= 1;
	}
	upd(x, y, f, k);
	
	f = 1, x = xx, y = yy;
	while (x > 0 && y > 0) {
		if (f) y--;
		else x--;
		f ^= 1;
	}
	upd(x, y, f, k);
}

void main_() {
	cin >> n >> m >> q;
	res = -n * m;
	
	forn (i, MX)
		a[0][i] = a[i][0] = 1;
	
	forn (i, n + 1) {
		if (!i) continue;
		
		upd(i, 0, 0, 1);
	}
	
	forn (j, m + 1) {
		if (!j) continue;
		
		upd(0, j, 1, 1);
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		
		upd(x, y, -1);
		res += !a[x][y];
		
		a[x][y] ^= 1;
		
		upd(x, y, 1);
		res -= !a[x][y];
		
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}