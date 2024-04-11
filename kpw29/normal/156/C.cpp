#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 200

int dp[101][101 * 26];
int t[maxn];

int main()
{
	boost;
	FOR(i, 0, 25) dp[1][i] = 1;
	FOR(i, 2, 100)
	  FOR(j, 0, 25 * i)
	    FOR(k, 0, 25)
	      if (j - k >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j - k])%mod;
	      
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int n = s.length();
		FOR(i, 0, n-1) t[i + 1] = s[i] - 'a';
		int sum = 0;
		FOR(i, 1, n) sum += t[i];
		cout << (dp[n][sum] - 1 + mod)%mod << "\n";
	}
}