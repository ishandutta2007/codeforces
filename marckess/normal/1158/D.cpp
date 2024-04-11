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

const int MX = 2005;
int n;
string s;
vii p, aux, hull, temp;
bitset<MX> ex;
ii act;
map<ii, int> mp;

ii operator - (ii a, ii b) { return {a.fi - b.fi, a.se - b.se}; }
ll operator ^ (ii a, ii b) { return 1ll * a.fi * b.se - 1ll * a.se * b.fi; }
int md (ii &o, ii &p, ii &q) {
	ll a = (p - o) ^ (q - o);
	return a ? (a > 0 ? 1 : -1) : 0;
}

vii convex_hull (vii &p) {
	sort(all(p));
	sort(p.begin()+1, p.end(), [&] (ii &a, ii &b) {
		return md(p[0], a, b) == 1;
	});

	vii res;
	for (int i = 0; i < p.size(); i++) {
		while (res.size() > 2 && md(*(res.end()-2), res.back(), p[i]) == -1)
			res.pop_back();
		res.pb(p[i]);
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	p.resize(n);
	forn(i,n) {
		cin >> p[i].fi >> p[i].se;
		mp[p[i]] = i + 1;
	}
	cin >> s;

	hull = convex_hull(p);
	act = hull[0];

	for (char c : s) {
		cout << mp[act] << " ";
		
		int i = 0;
		while (hull[i] != act) i++;
		if (c == 'L') i++;
		else i = i - 1 + (int)hull.size();
		if (i >= hull.size()) i -= (int)hull.size();

		temp.clear();
		for (ii &a : p) if (a != act) temp.pb(a);
		act = hull[i];
		p = temp;
		hull = convex_hull(p);
	}

	cout << mp[act] << " ";
	if (hull[0] == act) cout << mp[hull[1]];
	else cout << mp[hull[0]];
	cout << endl;

	return 0;
}