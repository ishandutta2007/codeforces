#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, a, b, c;
int t[maxn];
int dp[2010][2];

int main()
{
	boost;
	cin >> n >> m;
	if (n > m) OUT("Yes");
	int zero = 0;
	for (int i=1; i<=n; ++i) 
	{
		cin >> t[i];
		if (t[i] == 0) ++zero;
		t[i] = (t[i] % m);
	}

	if (zero) OUT("Yes");
	for (int i=1; i<=n; ++i)
	{
	  for (int j=0; j<m; ++j)
	    if (dp[j][0]) dp[(j + t[i]) % m][1] = 1;

	  for (int j=0; j<m; ++j) dp[j][0] |= dp[j][1];
	  dp[t[i]][0] = 1;
     }
     if (dp[0][0]) cout << "Yes";
     else cout << "No";
	
}