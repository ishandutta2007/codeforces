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

const int MX = 1000005, mod = 1000000007, inv2 = (mod + 1) / 2;
int n;
ll dp[MX], acu[MX], res[MX];

ll pot (ll b, int p){
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
	
	dp[n + 1] = acu[n + 1] = pot(inv2, n);
	
	for (int i = n; i >= 1; i--) {
		if (2 * i > n)
			dp[i] = acu[i + 1];
		else
			dp[i] = (acu[i + 1] - acu[2 * i]) % mod;
		(dp[i] *= pot(2, i)) %= mod;
		acu[i] = (dp[i] * pot(inv2, i) + acu[i + 1]) % mod;
		res[i] = pot(inv2, (i + 1) / 2) * dp[i] % mod;
	}
	(res[n] *= 2) %= mod;
	
	forr (i, 1, n)
		cout << MOD(res[i], mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}