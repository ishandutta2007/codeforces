#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 32000;
int n;
ll a[505], mn = 1e18;

ll sz (ll x) {
	ll sum = 0;
	if (x <= 0) return 1e18;
	for (int i = 0; i < n; i++) {
		ll d = (a[i] + x - 1) / x;
		if ((x - 1) * d > a[i]) return 1e18;
		sum += d;
	}
	return sum;
}

ll cn (ll k) {
	ll d = a[0] / k;
	return min({sz(d-1), sz(d), sz(d+1)});
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 1; i < MX; i++) {
		mn = min({mn, sz(i), cn(i)});
	}

	cout << mn << endl;

	return 0;
}