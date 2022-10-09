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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, k, a, b, c, w, h;
char s[maxn];
int dp[maxn][26], last[maxn][26];
PII SECOND, MIN;
inline PII minexc(int x) {
	if (x != MIN.e2) return MIN;
	return SECOND;
}
char ret[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	for (int i=1; i<=n; ++i)
	  for (int j=0; j<k; ++j) dp[i][j] = inf;
	MIN = {0, -1};
	SECOND = {0, 0};
	for (int i=1; i<=n; ++i)
	{
		for (int j=0; j<k; ++j)
		if (s[i] == (char)j + 'A') {
			dp[i][j] = minexc(j).e1;
			last[i][j] = minexc(j).e2;
		}
		else dp[i][j] = minexc(j).e1 + 1, last[i][j] = minexc(j).e2;
		MIN = {inf, inf}; SECOND = {inf, inf};
		for (int j=0; j<k; ++j)
		  if (dp[i][j] < MIN.e1) {
			  SECOND = MIN;
			  MIN = mp(dp[i][j], j);
		  }
		  else if (dp[i][j] < SECOND.e1) SECOND = mp(dp[i][j], j);
	}
	int res = inf, poz = inf;
	for (int i=0; i<k; ++i) if (dp[n][i] < res) res = dp[n][i], poz = i;
	cout << res << endl;
	if (res == 0) {
		for (int i=1; i<=n; ++i) printf("%c", s[i]);
		exit(0);
	}
	for (int i=n; i>0; --i)
	{
		ret[i] = poz + 'A';
		poz = last[i][poz];
	}
	for (int i=1; i<=n; ++i) printf("%c", ret[i]);
	
}