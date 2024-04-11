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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll s = 0;
ii a[MX];

bool esPos (ll m) {
	ll x = 0;
	int cn = 0;
	for (int i = n - 1; i + 1 && cn < (n + 1) / 2; i--) {
		if (a[i].fi >= m) {
			cn++;
		} else if (m <= a[i].se) {
			cn++;
			x += m - a[i].fi;
		}
	}

	return cn >= (n + 1) / 2 && x <= s;
}

void solve () {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i].fi >> a[i].se;
		s -= a[i].fi;
	}
	sort(a, a+n);

	ll i = 0, j = ll(1e14)+5, rep = 50;
	while (rep--) {
		ll m = (i + j + 1) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}
	cout << i << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}