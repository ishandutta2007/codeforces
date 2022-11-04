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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int q;
ll a, b, m, r[55];

void solve () {
	cin >> a >> b >> m;
	int res = -1;

	for (ll i = 1; a * (1ll << max(0ll, i - 2)) <= b; i++) {
		ll d = b - a * (1ll << max(0ll, i - 2));
		bool f = 1;

		for (int j = 2; j <= i; j++)
			d -= (1ll << max(0ll, i - j - 1));
		if (d < 0) continue;

		for (int j = 2; j <= i; j++) {
			ll x = 1ll << max(0ll, i - j - 1);
			r[j] = d / x;
			r[j] = min(r[j], m - 1);
			d -= x * r[j];
			r[j]++;
		}

		if (f && !d) {
			r[1] = a;
			res = i;
			break;
		}
	}

	cout << res;
	for (int i = 1; i <= res; i++) {
		ll x = 0;
		for (int j = 1; j <= i; j++)
			x += r[j] * (1ll << max(0, i - j - 1));
		cout << " " << x;
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> q;
	while (q--)
		solve();

	return 0;
}