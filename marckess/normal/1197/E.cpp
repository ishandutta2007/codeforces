#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, mod = 1000000007;
int n, res[MX], was[MX];
ii a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a, a + n, [&] (const ii& i, const ii& j) {
		return i.fi ^ j.fi ? i.fi < j.fi : i.se > j.se;
	});

	for (int i = 0; i < n; i++) {
		int j = (upper_bound(a, a+i, ii(a[i].se, 1e9+5)) - a) - 1;
		int mxin = 0; 
		was[i] = a[i].se;
		res[i] = 1;

		while (j >= 0) {
			if (a[j].fi <= mxin) break;
			int w = a[i].se - a[j].fi + was[j];

			if (was[i] > w) {
				was[i] = w;
				res[i] = res[j];
			} else if (was[i] == w) {
				was[i] = w;
				(res[i] += res[j]) %= mod;
			}

			mxin = max(mxin, a[j].se);
			j--;
		}
	}

	ll r = 0;
	int mx = 0, mn = 1e9+5;
	for (int i = 0; i < n; i++) 
		mx = max(mx, a[i].se);
	for (int i = 0; i < n; i++)
		if (a[i].fi > mx)
			mn = min(mn, was[i]);
	for (int i = 0; i < n; i++)
		if (a[i].fi > mx && was[i] == mn)
			(r += res[i]) %= mod;
	cout << r << endl;

	return 0;
}