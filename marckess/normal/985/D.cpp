#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;

ll n, h;

bool esPos (ll m) {
	ll acu = m * (m + 1) / 2;
	if (acu > n)
		return 0;

	if (m > h)
		acu += m * (m - 1) / 2 - h * (h - 1) / 2;

	return acu <= n;
}

ll obtTri (ll n) {
	ll i = 1, j = 1.5e9, rep = 32;

	while (rep--) {
		ll m = (i+j)/2;
		if (esPos(m))
			i = m;
		else
			j = m;
	}

	if (esPos(j))
		return j;
	return i;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> h;

	ll mx = obtTri(n);
	ll res = mx;
	n -= mx * (mx + 1) / 2;
	
	if (mx > h) {
		n -= mx * (mx - 1) / 2 - h * (h - 1) / 2;
		res += mx - h;
	}
	assert(n >= 0);

	ll d = n / mx, e = n % mx;
	
	cout << res + d + ll(e > 0) << endl;

	return 0;
}