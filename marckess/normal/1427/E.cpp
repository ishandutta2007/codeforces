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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vector<ll> b;
vector<string> res;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll add (ll a, ll b) {
	res.pb(to_string(a) + " + " + to_string(b));
	return a + b;
}

ll xo (ll a, ll b) {
	res.pb(to_string(a) + " ^ " + to_string(b));
	return a ^ b;
}

bool valid (ll a) {
	for (int i = b.size() - 1; i >= 0; i--)
		if ((a ^ b[i]) < a)
			a ^= b[i];
	return !a;
}

ll get (ll mk, int f = 0) {
	ll res = 0;
	forn (i, b.size()) if (mk & (1ll << i)) {
		if (f) xo(res, b[i]);
		res ^= b[i];
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll x;
	cin >> x;
	xo(x, x);	
	b.pb(x);
	
	while (!valid(1)) {
		ll i = uniform_int_distribution<ll>(0, (1ll << b.size()) - 1)(rng);
		ll j = uniform_int_distribution<ll>(0, (1ll << b.size()) - 1)(rng);
		ll x = get(i);
		ll y = get(j);
		
		if (x + y < 1e18 && !valid(x + y)) {
			get(i, 1), get(j, 1);
			ll a = add(x, y);
			
			for (int i = b.size() - 1; i >= 0; i--)
				if ((a ^ b[i]) < a)
					a = xo(a, b[i]);
			
			b.pb(a);
			sort(all(b));	
		}
	}
	
	cout << res.size() << endl;
	for (auto &r : res) cout << r << endl;
	
	return 0;
}