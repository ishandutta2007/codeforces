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
 
const int MX = 100005;
ll n;
ll a, r, m, h[MX], acu[MX], s;

ll solve (ll k) {
	ll x = 0, y = 0;
	ll i = lower_bound(h, h + n, k) - h;

	if (i) x = k * i - acu[i - 1];

	i = upper_bound(h, h + n, k) - h;

	if (i < n) y = (s - (i ? acu[i - 1] : 0)) - k * (n - i);

	ll d = min(x, y);

	return min(
		m * d + a * (x - d) + r * (y - d),
		a * x + r * y
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> a >> r >> m;
	forn (i, n) cin >> h[i];
	sort (h, h + n);

	acu[0] = h[0];
	for (int i = 1; i < n; i++)
		acu[i] = h[i] + acu[i - 1];
	s = acu[n - 1];

	ll res = min(solve(s / n), solve((s + n - 1) / n));
	forn (i, n)
		res = min(res, solve(h[i]));
	cout << res << endl;

	return 0;
}