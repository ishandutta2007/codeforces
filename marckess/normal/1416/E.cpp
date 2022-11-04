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

ll n, res, off, s;
set<ll> st;
ii r;

bool find (ll a) {
	return (r.fi <= a && a <= r.se) || st.count(s * (a - off));
}

void reset () {
	st.clear();
	off = 0;
	s = 1;
	r = {0, -1};
}

void solve () {
	cin >> n;
	
	reset();
	res = 0;
	
	forn (_, n) {
		ll a;
		cin >> a;
		
		r.se = min(r.se, a - 1);
		
		while (st.size() && off + s ** st.begin() >= a) st.erase(st.begin());
		while (st.size() && off + s ** st.rbegin() >= a) st.erase(*st.rbegin());
		
		if (a % 2 == 0 && find(a / 2)) {
			res += 2;
			reset();
			st.insert(a / 2);
		} else if (a % 2 == 0 || r.fi <= r.se || st.size()) {
			res++;
			if (a % 2 == 0)
				st.insert(s * (a / 2 - off));
		} else {
			r = {1, a - 1};
		}
		
		if (r.fi <= r.se) r = {a - r.se, a - r.fi};
		
		off = a - off;
		s = -s;
	}
	
	cout << 2 * n - res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 	
	int t;
	cin >> t;
	while (t--)
		solve(); 	

	return 0;
}