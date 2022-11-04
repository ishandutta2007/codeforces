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

const int MX = 200005, lim = 1e9;
int n, sx, sy, x[MX], y[MX];
vector<pair<int, ii>> res;

bool valid (int x, int y) {
	return 0 <= x && x <= lim && 0 <= y && y <= lim && (x != sx || y != sy);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> sx >> sy;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) {
			bool p = valid(sx + i, sy + j);
			if (p) {
				int cn = 0, a = sx + i, b = sy + j;

				for (int k = 0; k < n; k++) {
					int x1 = min(x[k], sx), x2 = max(x[k], sx);
					int y1 = min(y[k], sy), y2 = max(y[k], sy);

					cn += x1 <= a && a <= x2 && y1 <= b && b <= y2;
				} 

				res.emplace_back(cn, ii(a, b));
			}
		}

	sort(all(res));
	cout << res.back().fi << endl;
	cout << res.back().se.fi << " " << res.back().se.se << endl;

	return 0;
}