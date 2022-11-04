#include <bits/stdc++.h>

//#define endl '\n'
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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ll dp[MX], izq[MX], der[MX], sum;
ii a[MX];

void update (int i, ll k, ll ft[], int d) {
	while (i && i < MX) {
		ft[i] = min(ft[i], k);
		i += d * (i & -i);
	}
}

ll query (int i, ll ft[], int d) {
	ll res = 1e18;
	while (i && i < MX) {
		res = min(res, ft[i]);
		i -= d * (i & -i);
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, MX)
		izq[i] = der[i] = 1e18;
	
	cin >> n;	
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		sum += a[i].se;
	}
	sort(a + 1, a + n + 1);
	
	update(n, 0, izq, 1);
	update(n, a[n].fi, der, -1);
	
	for (int i = n - 1; i >= 1; i--) {
		int j = lower_bound(a + 1, a + n + 1, ii(a[i].fi + a[i].se, -1)) - a;
		
		dp[i] = 1e18;
		if (j - 1 > i) {
			dp[i] = min(dp[i], query(j - 1, izq, 1));
		}
		if (j <= n) {
			dp[i] = min(dp[i], query(j, der, -1) - a[i].fi - a[i].se);
		}
		
		update(i, dp[i], izq, 1);
		update(i, dp[i] + a[i].fi, der, -1);
	}
	
	cout << sum + dp[1] << endl;

	return 0;
}