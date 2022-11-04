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

const int MX = 100005;
int n, c[MX], a[MX], b[MX];
ll res, dp[MX];

void solve () {
	cin >> n;
	forn (i, n) cin >> c[i];
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	
	dp[0] = -1e18;
	res = 0;
	
	for (int i = 1; i < n; i++) {
		ll x = 0, y = 0;
		
		x = abs(a[i] - b[i]);
		
		if (a[i] != b[i]) {
			if (a[i] > b[i]) swap(a[i], b[i]);
			y = (a[i] - 1) + (c[i - 1] - b[i]) + 2 + dp[i - 1];
		}
		
		res = max(res, max(x, y) + 2 + c[i] - 1);
		dp[i] = max(x, y);
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