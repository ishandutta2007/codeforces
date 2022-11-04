#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define find(v,x) (lower_bound(all(v), x) - v.begin())
const int MX = 1e6;

struct Event {
	int a, b, x, k;

	Event () {}
	Event (int a, int b, int x, int k) : a(a), b(b), x(x), k(k) {}

	bool operator < (const Event &ot) const { return x < ot.x; }
};

int n, k, x, y;
ll acu[MX], ant[MX], res[MX];
vi cy, sz;
vector<Event> ve;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		cy.pb(y), cy.pb(y+1), cy.pb(y-k+1);
		ve.emplace_back(y-k+1, y, x-k+1, 1);
		ve.emplace_back(y-k+1, y, x+1, -1);
	}

	sort(all(cy));
	cy.erase(unique(all(cy)), cy.end());

	sz.resize(cy.size());
	for (int i = 0; i + 1 < sz.size(); i++)
		sz[i] = cy[i+1] - cy[i];

	sort(all(ve));

	for (Event &e : ve) {
		int a = find(cy, e.a);
		int b = find(cy, e.b);

		for (int i = a; i <= b; i++) {
			if (acu[i])
				res[acu[i]] += ll(e.x - ant[i]) * sz[i];
			
			acu[i] += e.k;
			ant[i] = e.x;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}