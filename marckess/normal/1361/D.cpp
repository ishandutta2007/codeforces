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

const ld eps = 1e-9;
const int MX = 1000005;
int n, k, ch, cn[MX];
ii p[MX];
map<ii, vii> mp;
ld s, res;
priority_queue<pair<ld, int>> pq;
vector<vii> v;

#define cost(j,p) ((ll(j + 1) * (k - j - 1) - ll(j) * (k - j)) * hypot(ld(p.fi), p.se))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i].fi >> p[i].se;

		if (!p[i].fi && !p[i].se) continue;
		int g = abs(__gcd(p[i].fi, p[i].se));
		ii m(p[i].fi / g, p[i].se / g);

		mp[m].pb(p[i]);
	}

	int i = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		v.pb(it->se);

		sort(all(v[i]), [&] (const ii &a, const ii &b) {
			if (a.fi == b.fi) return abs(a.se) > abs(b.se);
			return abs(a.fi) > abs(b.fi);
		});

		forn (j, v[i].size())
			pq.emplace(cost(j, v[i][j]), i);
		i++;
	}

	while (pq.size() && ch < k) {
		auto v = pq.top();
		pq.pop();

		if (v.fi < 0) break;

		s += v.fi;
		cn[v.se]++;
		ch++;
	}

	forn (i, v.size()) 
		if (k - ch - 1 <= (int)v[i].size() - cn[i]) {
			ld x = 0;
			for (int j = int(v[i].size()) - (k - ch - 1); j < v[i].size(); j++, cn[i]++)
				x += cost(cn[i], v[i][j]);
			res = max(res, s + x);
		}

	cout << res << endl;

	return 0;
}