#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 1 << 20, mod = 1e9 + 7;
int n, a[MX];
ll res, dp[MX];

void sum (ll &a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		dp[a[i]]++;
	}
	
	forn (i, (1 << 20))
		dp[i] = pot(2, dp[i]);
	
	forn (j, 20)
		forn (i, (1 << 20))
			if (~i & (1 << j))
				(dp[i] *= dp[i | (1 << j)]) %= mod;
	
	forn (i, (1 << 20))
		sum(res, dp[i] * ((__builtin_popcount(i) & 1) ? -1 : 1));
	cout << MOD(res, mod) << endl;
	
	return 0;
}