#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
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

ll x, y, res;

void solve () {
	cin >> x >> y;
	res = 0;
	
	ll lim = sqrt(x + 1) + 5;
	
	for (ll b = 2; b <= min(lim, y + 1); b++)
		res += min(x, (b - 1) * (b - 1) - 1) / b;
	
	for (ll k = 1; k < lim; k++) {
		ll d = min(y + 1, x / k);
		if (d > lim)
			res += d - lim;
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}