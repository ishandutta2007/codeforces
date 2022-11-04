#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

ll n, u, r;
ll a[33][33], b[33], k[33], p[33];

ll dfs (int i, int f) {
	ll res = -1e18;

	if ((u - i) % 2 == 0) {
		ll s = 0;
		forn (j, n)
			s += a[i][j] * k[j];
		res = s;
	}
	
	if (u == i) return res;

	forn (j, n)
		a[i + 1][j] = a[i][p[j] - 1] + r;

	res = max(res, dfs(i + 1, 1));

	if (f) {
		forn (j, n)
			a[i + 1][j] = a[i][j] ^ b[j];
		res = max(res, dfs(i + 1, 0));
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> u >> r;
	forn (i, n) cin >> a[0][i];
	forn (i, n) cin >> b[i];
	forn (i, n) cin >> k[i];
	forn (i, n) cin >> p[i];
	cout << dfs(0, 1) << endl;

	return 0;
}