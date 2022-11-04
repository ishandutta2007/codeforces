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

const int MX = 200005, mod = 1000000007;
int n, b[MX];
ll dp[MX], dp2[MX], sum, off;
map<ll, ll> mp;

void solve () {
	cin >> n;
	
	mp.clear();
	off = 0;
	
	sum = 1;
	dp[0] = 1;
	mp[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		
		dp2[i] = sum;
		if (mp.count(off))
			dp2[i] -= mp[off];
		dp2[i] %= mod;
		
		dp[i] = (dp[i - 1] + dp2[i]) % mod;
		
		(mp[off] += dp2[i]) %= mod;
		off += b[i];
		(sum += dp2[i]) %= mod;
	}
	
	cout << (dp[n] + mod) % mod << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}