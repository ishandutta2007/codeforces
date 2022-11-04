#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
ll n, a[MX], res, s, acu;
int m;
multiset<ll> st;

void solve () {
	st.clear();
	s = res = acu = 0;

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		s += a[i];
		st.insert(a[i]);
	}

	if (s < n) {
		cout << -1 << endl;
		return;
	}

	for (int i = 0; n; i++) {
		while (st.size() && *st.begin() == (1ll << i)) {
			st.erase(st.begin());
			acu++;
		}

		if (n & (1ll << i)) {
			if (acu) {
				acu--;
			} else {
				if (st.empty()) {
					cout << -1 << endl;
					return;
				}

				ll x = *st.begin();
				st.erase(st.begin());

				while (x > (1ll << i)) {
					x /= 2;
					st.insert(x);
					res++;
				}
			}

			n ^= (1ll << i);
		}

		while (st.size() && *st.begin() == (1ll << i)) {
			st.erase(st.begin());
			acu++;
		}

		acu /= 2;
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