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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1e7;
ll c, hr, hb, wr, wb, res;

void solve () {
	for (ll a = 0; a < MX && a * wr <= c; a++) {
		ll x = a * hr;
		ll y = ((c - a * wr) / wb) * hb;
		res = max(res, x + y);
	}

	for (ll a = c / wr; a >= 0 && a >= c / wr - MX; a--) {
		ll x = a * hr;
		ll y = ((c - a * wr) / wb) * hb;
		res = max(res, x + y);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> c >> hr >> hb >> wr >> wb;

	solve();
	swap(hr, hb);
	swap(wr, wb);
	solve();

	cout << res << endl;

	return 0;
}