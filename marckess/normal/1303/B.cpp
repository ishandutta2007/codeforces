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

ll n, g, b;

bool esPos (ll m) {
	ll k = g * (m / (g + b));
	k += min(g, m % (g + b));
	return m >= n && k >= (n + 1) / 2;
}

void solve () {
	cin >> n >> g >> b;

	ll i = 0, j = ll(1e18) + 5, rep = 64;
	while (rep--) {
		ll m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << j << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}