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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
map<ll, vii> mx, my;
set<ll> st;
ll g;

void no () {
	cout << 0 << endl;
	exit(0);
}

void check () {
	set<vi> sv;

	for (auto it : mx) {
		vii v = it.se; 
		sort(all(v));

		if (v.size() != my.size()) no();
		vi w;

		ll f = 0;
		for (ii &x : v) x.se /= g;
		for (ii &x : v) f = __gcd(f, x.se);
		for (ii &x : v) w.pb(x.se / f);
		
		sv.insert(w);
	}

	if (sv.size() != 1) no();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		ll x, y, c;
		cin >> x >> y >> c;
		mx[x].emplace_back(y, c), my[y].emplace_back(x, c);
		g = __gcd(g, c);
	}

	check();
	swap(mx, my);
	check();

	for (ll i = 1; i * i <= g; i++)
		if (g % i == 0)
			st.insert({i, g / i});

	cout << st.size() << endl;

	return 0;
}