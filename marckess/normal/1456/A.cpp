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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
ll n, p, k, dp[MX];
string s;
ll x, y, res;

void solve () {
	cin >> n >> p >> k >> s >> x >> y;
	res = x * n;
	
	for (int i = n - 1; i >= p - 1; i--) {
		if (s[i] == '0') dp[i] = x;
		else dp[i] = 0;
		
		if (i + k < n) dp[i] += dp[i + k];
		
		res = min(res, dp[i] + (i - (p - 1)) * y);
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}