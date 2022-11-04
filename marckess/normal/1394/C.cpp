#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, mnx = MX, mny = MX;
ii a[MX];
string s[MX];

int dis (const ii &a, const ii &b) {
	int dx = a.fi - b.fi;
	int dy = a.se - b.se;

	if (dx < 0 && dy < 0) return -min(dx, dy);
	if (dx > 0 && dy > 0) return max(dx, dy);

	return abs(dx) + abs(dy);
}

ii esPos (int m) {
	int x = mnx + m;
	int y = mny + m;

	forn (i, n) {
		if (x <= a[i].fi && a[i].fi <= x + m && a[i].se < y && dis({x, y}, a[i]) > m)
			y -= dis({x, y}, a[i]) - m;

		if (y <= a[i].se && a[i].se <= y + m && a[i].fi < x && dis({x, y}, a[i]) > m)
			x -= dis({x, y}, a[i]) - m;
	}

	forn (i, n) if (dis({x, y}, a[i]) > m) return {-1, -1};
	return {x, y};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	forn (i, n) {
		cin >> s[i];
		
		for (char c : s[i]) {
			if (c == 'B') a[i].fi++;
			else a[i].se++;
		}
		
		mnx = min(mnx, a[i].fi);
		mny = min(mny, a[i].se);
	}

	int i = 0, j = MX;

	while (i < j) {
		int m = (i + j) / 2;
		if (esPos(m).fi != -1) j = m;
		else i = m + 1;
	}

	ii res = esPos(j);

	cout << j << endl;
	forn (i, res.fi) cout << 'B';
	forn (i, res.se) cout << 'N';
	cout << endl;

	return 0;
}