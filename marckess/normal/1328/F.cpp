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

const int MX = 200005;
ll n, k, a[MX];
map<int, int> ini, fin;
ll acu[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	forn (i, n) cin >> a[i + 1];
	sort (a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++) {
		acu[i] = a[i] + acu[i - 1];
		if (!ini[a[i]]) ini[a[i]] = i;
		fin[a[i]] = i;
	}

	ll res = acu[n];
	for (int i = 1; i <= n; i++) {
		ll l = ini[a[i]], r = fin[a[i]];
		ll x = (l - 1) * (a[i] - 1) - acu[l - 1];
		ll y = (acu[n] - acu[r]) - (n - r) * (a[i] + 1);

		int act = r - l + 1;
		if (act >= k) res = 0;
		if (l - 1 >= k - act) res = min(res, x + max(0ll, k - act));
		if (n - r >= k - act) res = min(res, y + max(0ll, k - act));
		res = min(res, x + y + max(0ll, k - act));
	}

	cout << res << endl;

	return 0;
}