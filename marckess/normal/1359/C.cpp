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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll c, h, t;

bool comp (__int128 a, __int128 b, __int128 c, __int128 d) {
	return a * d < c * b;
}

ll f (ll j) {
	return abs(h * (j + 1) + c * j - t * (2 * j + 1));
}

void solve () {
	cin >> h >> c >> t;

	ll ini;
	if (h + c - 2 * t) ini = (t - h) / (h + c - 2 * t) - 10;
	else ini = 0;

	ini = max(ini, 0ll);
	ll fin = ini + 20;

	ll ind = ini;
	for (ll i = ini + 1; i <= fin; i++)
		if (comp(f(i), 2 * i + 1, f(ind), 2 * ind + 1))
			ind = i;

	if (2 * ind + 1 < 2) {
		if (comp(abs(c + h - 2 * t), 2, f(ind), 2 * ind + 1))
			cout << 2 << endl;
		else
			cout << 2 * ind + 1 << endl;
	} else {
		if (comp(f(ind), 2 * ind + 1, abs(c + h - 2 * t), 2))
			cout << 2 * ind + 1 << endl;
		else
			cout << 2 << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(2);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}