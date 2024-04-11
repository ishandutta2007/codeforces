
// Problem : F. Sports Betting
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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

const int MX = 1 << 14, mod = 1000000007;
int n;
ll a[22], dp[MX], adj[22][22];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	forn (i, n)
		cin >> a[i];
		
	forn (i, n)
		forn (j, n)
			adj[i][j] = a[i] * pot(a[i] + a[j], mod - 2) % mod;
	
	ll res = 0;
	forn (mk, 1 << n) {
		if (!mk) continue;
		
		dp[mk] = 1;
		vector<ll> acu(n, 1);
		
		forn (i, n)
			if (mk & (1 << i)) {
				forn (j, n)
					if (~mk & (1 << j))
						(acu[i] *= adj[i][j]) %= mod;
				(dp[mk] *= acu[i]) %= mod;
			}
		
		for (int sub = (mk - 1) & mk; sub; sub = (sub - 1) & mk) {
			ll p = dp[sub];
			
			forn (i, n)
				if (mk & (1 << i))
					if (~sub & (1 << i))
						(p *= acu[i]) %= mod;
			
			dp[mk] += mod - p;
			if (dp[mk] >= mod)
				dp[mk] -= mod;
		}
		
		(res += ll(__builtin_popcount(mk)) * dp[mk]) %= mod; 
	}
	
	cout << res << endl;
	
	return 0;
}