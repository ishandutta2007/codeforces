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

const int MX = 300005, mod = 998244353;
int n, m, cn;
ll dp[MX];
string s[MX];

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
	
	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i < MX; i++)
		dp[i] = (pot(2, i - 1) + dp[i - 2]) % mod;
	
	cin >> n >> m;
	forn (i, n)
		cin >> s[i];
	
	forn (i, n)
		forn (j, m)
			cn += s[i][j] == 'o';
	
	ll res = 0;
	forn (i, n) {
		int acu = 0;
		forn (j, m) {
			if (s[i][j] == 'o')
				acu++;
			else
				acu = 0;
			
			if (acu >= 2)
				(res += dp[acu - 2] * pot(2, cn - acu)) %= mod;
		}
	}
	
	forn (j, m) {
		int acu = 0;
		forn (i, n) {
			if (s[i][j] == 'o')
				acu++;
			else
				acu = 0;
			
			if (acu >= 2)
				(res += dp[acu - 2] * pot(2, cn - acu)) %= mod;
		}
	}
	
	cout << res << endl;
	
	return 0;
}