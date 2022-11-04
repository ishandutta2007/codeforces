#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 5005;
const ll inf = 1e18;
ll p1, t1, p2, t2, h, s, dp[MX][MX], res;

void mini (ll &a, ll b) {
	if (a > b)
		a = b;
}

void tran (int i, int ni, int j, int nj, ll t) {
	if (ni <= 0) {
		res = min(res, dp[i][j] + t);
	} else {
		mini(dp[ni][nj], dp[i][j] + t);
	}
}

void main_() {
	cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
	
	res = inf;
	forn (i, MX)
	forn (j, MX)
		dp[i][j] = inf;
	dp[h][0] = 0;
	
	for (int i = h; i > 0; i--) {
		ll x = t1, y = t2;
		
		for (int j = 0; j < h + 2; j++) {
			ll d = -s;
			if (x <= y) d += p1;
			if (y <= x) d += p2;
			tran(i, i - d, j, j + 1, min(x, y));
			
			d = p1 + p2 - s;
			tran(i, i - d, j, 0, max(x, y));
			
			d = min(x, y);
			x = x > d ? x - d : t1;
			y = y > d ? y - d : t2;
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}