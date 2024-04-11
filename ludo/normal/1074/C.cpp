#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, minx = 1e9, miny = 1e9, maxx = -1e9, maxy = -1e9;
	cin >> n;

	vii poly;
	REP(i, n) {
		int x, y;
		cin >> x >> y;
		poly.eb(x, y);
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
	}

	int dx = maxx - minx;
	int dy = maxy - miny;

	int f3 = 0;

	/*int maxdiffx = 0;
	int maxdiffy = 0;
	*/
	REP(i, n) {
		int fdx = max(poly[i].x - minx, maxx - poly[i].x);
		int fdy = max(poly[i].y - miny, maxy - poly[i].y);

		f3 = max(f3, fdx + fdy);

		/*if (minx == poly[i].x || maxx == poly[i].x) maxdiffy = max(maxdiffy, fdy);
		if (miny == poly[i].y || maxy == poly[i].y) maxdiffx = max(maxdiffx, fdx);
		*/
	}

	// f3 = max(maxdiffy + dx, maxdiffx + dy);

	cout << f3 + f3;
	for (int m = 4; m <= n; m++) cout << " " << (dx + dy + dx + dy);
	cout << endl;
	return 0;
}