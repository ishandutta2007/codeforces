#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll a, b, c, d;

void solve () {
	cin >> a >> b >> c >> d;
	if (a > b * c) {
		cout << -1 << endl;
		return;
	}
	ll t = (2 * a - d * b) / (2 * d * b);
	ll res = a;
	for (int ini = max(0ll, t - 5), i = 0; i < 10; i++) {
		ll x = ini + i;
		ll y = -a * (x + 1) + d * b * (x) * (x + 1) / 2;
		res = max(res, -y);
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