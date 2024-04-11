#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 200005, mod = 998244353;
int n, a[MX];
ll dp[MX];

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
	cin >> n;
	int c = 0;
	
	forn (i, n) {
		cin >> a[i];
		c += a[i] == 0;
	}
	
	int u = 0;
	forn (i, c)
		u += a[i] == 1;
	
	dp[0] = 0;
	forr (i, 1, u) {
		ll x = (1ll * i * i) % mod;
		ll y = (1ll * n * (n - 1) / 2) % mod;
		dp[i] = (x * dp[i - 1] + y) % mod * pot(x, mod - 2) % mod;
	}
	
	cout << dp[u] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}