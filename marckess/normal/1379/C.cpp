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

const int MX = 100005;
int n, m;
ii a[MX];
multiset<int> st;
ll sum, res;

void solve () {
	cin >> n >> m;
	forn (i, m)
		cin >> a[i].fi >> a[i].se;

	sort(a, a + m, [&] (const ii &x, const ii &y) {
		return x.se < y.se;
	});

	sum = 0, res = 0;
	st.clear();

	forn (i, m) {
		ll p = a[i].fi;

		while (st.size() && (st.size() >= n || *st.begin() <= a[i].se)) {
			sum -= *st.begin();
			st.erase(st.begin());
		}

		p += sum;
		p += ll(n - (int)st.size() - 1) * a[i].se;

		res = max(res, p);

		st.insert(a[i].fi);
		sum += a[i].fi;
	}

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