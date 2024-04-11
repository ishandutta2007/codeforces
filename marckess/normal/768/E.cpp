#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

map<ii, int> dp;

int mex (ll n) {
	for (int i = 0;; i++)
		if (!(n & (1ll << i)))
			return i;
}

int grund (int n, ll mk) {
	if (n == 0)
		return 0;

	if (dp.count(ii(n, mk)))
		return dp[ii(n, mk)];

	ll acu = 0;
	for (int i = 1; i <= n; i++)
		if (!(mk & (1ll << i)))
			acu |= 1 << grund(n - i, mk | (1ll << i));
	
	return dp[ii(n, mk)] = mex(acu);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, s;
	ll g = 0;

	cin >> n;
	while (n--) {
		cin >> s;
		g ^= grund(s, 0);
	}

	if (g) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}