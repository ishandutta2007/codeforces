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

const int MX = 100005, mod = 1e9+7;
int n;
ll x, y, res = 0;
ii a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> a[i].fi >> a[i].se;
		res += y * (a[i].se - a[i].fi);
		res %= mod;
	}
	sort(a, a+n);

	multiset<int> st;

	for (int i = 0; i < n; i++) {
		auto it = st.lower_bound(a[i].fi);

		if (it == st.begin()) {
			res += x;
		} else {
			it--;
			res += min(x, y * (a[i].fi - *it));
			st.erase(it);
		}
		res %= mod;

		st.insert(a[i].se);
	}

	cout << res << endl;

	return 0;
}