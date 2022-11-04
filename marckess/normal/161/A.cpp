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

const int MX = 100005;
int n, m, x, y, a[MX];
ii b[MX];
pair<ii, int> p[MX];
vii res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> x >> y;
	
	forn (i, n) {
		cin >> a[i];
		p[i] = {{a[i] - x, a[i] + y}, i};
	}
	sort(p, p + n);

	forn (i, m) {
		cin >> b[i].fi;
		b[i].se = i;
	}
	sort(b, b + m);

	int i = 0, j = 0;
	while (i < n) {
		while (j < m && b[j].fi < p[i].fi.fi) j++;
		if (j < m && b[j].fi <= p[i].fi.se) {
			res.emplace_back(p[i].se, b[j].se);
			j++;
		}
		i++;
	}

	cout << res.size() << endl;
	for (ii &r : res)
		cout << r.fi + 1 << " " << r.se + 1 << endl;

	return 0;
}