
// Problem : E. Mocha and Stars
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 998244353;
int n, dp[55][MX], l[MX], r[MX], m, mu[MX], bs[MX];
int a[MX], b[MX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fill(mu, mu + MX, 1);
	
	for (int i = 2; i < MX; i++)
		if (!bs[i]) {
			for (int j = i; j < MX; j += i) {
				bs[j] = 1;
				mu[j] *= -1;
			}
			
			for (ll j = 1ll * i * i; j < MX; j += i * i)
				mu[j] = 0;
		}
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	
	int res = 0;
	
	for (int s = 1; s <= m; s++) {
		if (!mu[s]) continue;
		
		int f = 1;
		for (int i = 1; i <= n; i++) {
			a[i] = (l[i] + s - 1) / s;
			b[i] = r[i] / s;
			if (a[i] > b[i])
				f = 0;
		}
		
		if (!f) continue;
		
		int x = m / s;
		for (int i = 1; i <= n; i++) {
			x -= a[i];
			b[i] -= a[i];
		}
		
		if (x < 0) continue;
		
		forn (i, n + 1)
			forn (j, x + 1)
				dp[i][j] = 0;
		
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int acu = 0;
			
			for (int j = 0; j <= x; j++) {
				acu += dp[i - 1][j];
				if (acu >= mod) acu -= mod;
				
				if (j - b[i] - 1 >= 0) {
					acu -= dp[i - 1][j - b[i] - 1];
					if (acu < 0) acu += mod;
				}
				
				dp[i][j] = acu;
			}
		}
		
		int p = 0;
		forn (i, x + 1) {
			p += dp[n][i];
			if (p >= mod)
				p -= mod;
		}
		
		res += mu[s] * p;
		if (res < 0) res += mod;
		if (res >= mod) res -= mod;
	}
	
	cout << res << endl;
	
	return 0;
}