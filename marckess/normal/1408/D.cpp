#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 1000005;
int n, m, mx[MX], res;
ii a[2005], b[2005];

void solve () {
	cin >> n >> m;

	res = 2 * MX;

	forn (i, n) cin >> a[i].fi >> a[i].se;
	forn (i, m) cin >> b[i].fi >> b[i].se;

	forn (i, n) forn (j, m)	{
		int d = b[j].fi - a[i].fi;
		if (d >= 0) mx[d] = max(mx[d], b[j].se - a[i].se + 1);
	}

	int act = 0;
	for (int i = MX - 1; i >= 0; i--) {
		act = max(mx[i], act);
		res = min(res, i + act);
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)	
		solve();

	return 0;
}