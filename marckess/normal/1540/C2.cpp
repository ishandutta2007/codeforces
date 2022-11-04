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

const int MX = 105, mod = 1000000007;
int n, q, dp[MX][MX * MX], ned[MX], c[MX], b[MX], off[MX];
ll all = 1;
map<int, int> mp;

int solve (int x) {
	int f = 1, pos = 1;
	
	forn (i, n) {
		ned[i] = (i + 1) * x + off[i];
		
		if (100 * (i + 1) < ned[i]) pos = 0;
		if (ned[i] >= 1) f = 0;
	}
	
	if (!pos) return 0;
	if (f) return all;
	
	memset(dp, 0, sizeof(dp));
	
	for (int s = max(0, ned[n - 1]); s <= 100 * n; s++)
		dp[n][s] = 1;
	
	for (int i = n - 1; i >= 0; i--) {
		int acu = 0;
		
		for (int s = 100 * i + 1; s <= 100 * i + c[i] + 1; s++) {
			acu += dp[i + 1][s];
			if (acu >= mod)
				acu -= mod;
		}
		
		for (int s = 100 * i; s >= (i ? max(0, ned[i - 1]) : 0); s--) {
			acu += dp[i + 1][s];
			if (acu >= mod)
				acu -= mod;
				
			acu -= dp[i + 1][s + c[i] + 1];
			if (acu < 0)
				acu += mod;
			
			dp[i][s] = acu;
		}
	}
	
	return dp[0][0];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	forn (i, n) cin >> c[i];
	forn (i, n - 1) cin >> b[i];
	cin >> q;
	
	forn (i, n) {
		(all *= c[i] + 1) %= mod;
		
		for (int j = i - 1, k = 1; j >= 0; j--, k++)
			off[i] += k * b[j];
	}
	
	while (q--) {
		int x;
		cin >> x;
		
		if (!mp.count(x))
			mp[x] = solve(x);
		
		cout << mp[x] << endl;
	}
		
	return 0;
}