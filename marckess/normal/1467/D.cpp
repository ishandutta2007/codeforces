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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005, mod = 1000000007;
int n, k, q;
ll a[MX], b[MX], res, dp[MX][MX];

void sum (ll &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
		dp[0][i] = 1;
		
	for (int j = 0; j <= k; j++)
		for (int i = 1; i <= n; i++) {
			if (i > 1) sum(dp[j + 1][i - 1], dp[j][i]);
			if (i < n) sum(dp[j + 1][i + 1], dp[j][i]);
		}
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			sum(b[i], dp[j][i] * dp[k - j][i] % mod);
	
	for (int i = 1; i <= n; i++)
		(res += a[i] * b[i]) %= mod;
	
	while (q--) {
		int i, x;
		cin >> i >> x;
		
		(res -= a[i] * b[i]) %= mod;
		a[i] = x;
		(res += a[i] * b[i]) %= mod;
		
		cout << MOD(res, mod) << endl;
	}
	
	return 0;
}