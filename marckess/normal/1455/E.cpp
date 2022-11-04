#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll x[4], y[4];

ll go (ii a, ii b, ii c, ii d) {
	ll res = 0;
	
	#define norm(p) res += abs(p.fi - p.se); if (p.fi > p.se) swap(p.fi, p.se); 
	
	norm(a);
	norm(b);
	norm(c);
	norm(d);
	
	ll x_mx = max(abs(b.se - a.fi), abs(a.se - b.fi));
	ll x_mn = max(a.fi, b.fi) <= min(a.se, b.se) ? 
		0 : 
		min(abs(b.se - a.fi), abs(a.se - b.fi));
	
	ll y_mx = max(abs(d.se - c.fi), abs(c.se - d.fi));
	ll y_mn = max(c.fi, d.fi) <= min(c.se, d.se) ?
		0 :
		min(abs(d.se - c.fi), abs(c.se - d.fi));
	
	if (max(x_mn, y_mn) > min(x_mx, y_mx))
		res += 2 * min(abs(y_mn - x_mx), abs(x_mn - y_mx));
	
	return res;
}

void solve () {
	ll res = 0;
	
	forn (i, 4) {
		cin >> x[i] >> y[i];
		res += x[i];
		res += y[i];
	}
	
	res = min(res, go({x[0], x[1]}, {x[2], x[3]}, {y[0], y[2]}, {y[1], y[3]}));
	res = min(res, go({x[0], x[1]}, {x[2], x[3]}, {y[0], y[3]}, {y[1], y[2]}));
	res = min(res, go({x[0], x[2]}, {x[1], x[3]}, {y[0], y[1]}, {y[2], y[3]}));
	res = min(res, go({x[0], x[2]}, {x[1], x[3]}, {y[0], y[3]}, {y[2], y[1]}));
	res = min(res, go({x[0], x[3]}, {x[1], x[2]}, {y[0], y[1]}, {y[3], y[2]}));
	res = min(res, go({x[0], x[3]}, {x[1], x[2]}, {y[0], y[2]}, {y[3], y[1]}));
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}