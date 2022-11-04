// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 2005, mod = 1000000007;
ll n, m, k, dp[MX][MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void main_() {
	cin >> n >> m >> k;
	cout << MOD(k * dp[n][m], mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	dp[0][0] = 0;
	for (int i = 1; i < MX; i++) {
		dp[i][0] = 0;
		dp[i][i] = i;
		
		for (int j = 1; j < i; j++) {
			ll x = dp[i - 1][j - 1];
			ll y = dp[i - 1][j];
			ll k = (y - x) * pot(2, mod - 2) % mod;
			
			dp[i][j] = (x + k) % mod;
		}
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}