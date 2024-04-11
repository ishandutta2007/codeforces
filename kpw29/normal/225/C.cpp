 #include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
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
#define maxn 1010

int C[maxn][2], n, m, x, y;
char s[maxn];
int dp[maxn][maxn][2], M[2];

int main() {
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i=1; i<=n; ++i) {
		scanf("%s", s + 1);
		for (int j=1; j<=m; ++j)
		  if (s[j] == '#') C[j][0]++;
		  else C[j][1]++;
	 }
	 for (int i=0; i<=m; ++i)
	   for (int j=0; j<=y; ++j)
	     for (int k=0; k<2; ++k) dp[i][j][k] = inf;
	 dp[0][0][0] = 0, dp[0][0][1] = 0;
	 
	 for (int i=1; i<=m; ++i) {
		 M[0] = M[1] = inf;
		 for (int j=x; j<=y; ++j) {
			 M[0] = min(M[0], dp[i-1][j][1]);
			 M[1] = min(M[1], dp[i-1][j][0]);
		 }
		 for (int zn = 0; zn < 2; ++zn) dp[i][1][zn] = min(dp[i][1][zn], M[zn] + C[i][zn]);
		 for (int j=1; j<=y; ++j)
		   for (int zn = 0; zn < 2; ++zn) dp[i][j][zn] = min(dp[i][j][zn], dp[i - 1][j - 1][zn] + C[i][zn]);
	 }
	 
	 
	 int wyn = inf;
	 for (int i=x; i<=y; ++i) wyn = min(wyn, min(dp[m][i][0], dp[m][i][1]));
	 cout << wyn;
}