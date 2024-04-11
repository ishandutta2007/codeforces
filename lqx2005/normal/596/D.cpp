#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
typedef double db;
const int N = 2000 + 10;
const int inf = 5e8;
int n, h;
db p;
int x[N];
db dp[N][N][2][2];
db DP(int l, int r, int a, int b)
{
	if(dp[l][r][a][b] >= 0) return dp[l][r][a][b];
	db &res = dp[l][r][a][b];
	if(l > r) return res = 0;
	int L = x[l - 1] + h * a;
	int R = x[r + 1] + h * (b - 1);
	if(l == r)
	{
		if(L > x[l]) return res = min(R - x[l], h);
		if(R < x[l]) return res = min(x[l] - L, h);
		return res = min(x[l] - L, h) * p + min(R - x[l], h) * (1 - p);
	}
	if(L > x[l]) return res = DP(l + 1, r, a, b) + min(x[l + 1] - x[l], h);
	if(R < x[r]) return res = DP(l, r - 1, a, b) + min(x[r]- x[r - 1], h);
	res = 0;
	res += (DP(l + 1, r, 0, b) + min(x[l] - L, h)) * p;
	res += (DP(l + 1, r, 1, b) + min(x[l + 1] - x[l], h)) * (1 - p);
	res += (DP(l, r - 1, a, 1) + min(R - x[r], h)) * (1 - p);
	res += (DP(l, r - 1, a, 0) + min(x[r] - x[r - 1], h)) * p;
	res /= 2;
	return res;
}
int main()
{
	scanf("%d%d%lf", &n, &h, &p);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 0; k <= 1; k++) for(int l = 0; l <= 1; l++) dp[i][j][k][l] = -1;
	sort(x + 1, x + n + 1);
	x[0] = -inf;
	x[n + 1] = inf;
	printf("%.10lf\n", DP(1, n, 0, 1));
  return 0;
}