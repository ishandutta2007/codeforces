#include <cstdio>
#include <cstring>
const int MAXN = 505, INF = 0x3f3f3f3f;

int dp[MAXN][MAXN], n, c[MAXN];
bool palin[MAXN][MAXN];

inline int min(int a, int b){return a > b ? b : a;}
int dfs(int l, int r){
	if(dp[l][r] != INF) return dp[l][r];
	if(r < l) return dp[l][r] = 0;
	if(palin[l][r]) return dp[l][r] = 1;
	int &now = dp[l][r], i;
	for(i = l; i < r; ++ i)
		now = min(now, dfs(l, i) + dfs(i + 1, r));
	for(i = 1; l + i - 1 < r - i + 1 && c[l + i - 1] == c[r - i + 1]; ++ i)
		now = min(now, dfs(l + i, r - i));
	return now;
}
int main(){
	int i, j;
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i) scanf("%d", &c[i]);
	for(i = 1; i <= n; ++ i){
		palin[i][i] = true;
		for(j = 1; i - j >= 1 && i + j <= n && c[i - j] == c[i + j]; ++ j)
			palin[i - j][i + j] = true;
	}
	for(i = 1; i < n; ++ i)
		for(j = 1; i - j + 1 >= 1 && i + j <= n && c[i - j + 1] == c[i + j]; ++ j)
			palin[i - j + 1][i + j] = true;
	printf("%d\n", dfs(1, n));
	return 0;
}