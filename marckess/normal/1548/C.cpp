
// Problem : C. The Three Little Pigs
// Contest : Codeforces - Codeforces Round #736 (Div. 1)
// URL : https://codeforces.com/contest/1548/problem/C
// Memory Limit : 512 MB
// Time Limit : 1000 ms
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

const int MX = 3000005, mod = 1000000007;
int n, q;
ll fac[MX], inv[MX], dp[MX][3];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

const ll inv3 = pot(3, mod - 2);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i < MX; i++)
		fac[i] = fac[i - 1] * i % mod;
	
	for (int i = 2; i < MX; i++)
		inv[i] = (inv[mod % i] * (mod - mod / i)) % mod;;
	
	for (int i = 1; i < MX; i++)
		(inv[i] *= inv[i - 1]) %= mod;
	
	cin >> n >> q;
	
	dp[0][0] = dp[0][1] = dp[0][2] = n;
	for (int i = 1; i <= 3 * n; i++) {
		dp[i][1] = (comb(3 * n, i + 1) + dp[i - 1][0] - dp[i - 1][1]) % mod;
		(dp[i][1] *= inv3) %= mod;
		dp[i][0] = (dp[i][1] - dp[i - 1][0]) % mod;
		dp[i][2] = (dp[i][1] + dp[i - 1][1]) % mod;
	}
	
	while (q--) {
		int x;
		cin >> x;
		cout << MOD(dp[x][0] + comb(3 * n, x), mod) << endl;
	}
	
	return 0;
}