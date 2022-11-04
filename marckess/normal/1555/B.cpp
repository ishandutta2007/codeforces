
// Problem : B. Two Tables
// Contest : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1555/problem/B
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

void solve () {
	int n, m, x1, x2, y1, y2, w, h;
	
	cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> w >> h;
	
	if ((x2 - x1) + w > n && (y2 - y1) + h > m) {
		cout << -1 << endl;
		return;
	}
	
	int res = 1e9;
	
	if ((x2 - x1) + w <= n) {
		res = min({
			res,
			max(w - x1, 0),
			max(x2 - (n - w), 0)
		});
	}
	
	if ((y2 - y1) + h <= m) {
		res = min({
			res,
			max(h - y1, 0),
			max(y2 - (m - h), 0)
		});
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}