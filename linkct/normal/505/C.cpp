#include <cstdio>
#include <cstring>
const int ZERO = 250, MAXN = 30005;

int dp[MAXN][(ZERO << 1) + 100], d, n, ans, cnt[MAXN], maxt;

inline int max(int a, int b){return a > b ? a : b;}
int dfs(int pos, int len){
	if(dp[pos][len + ZERO] != -1) return dp[pos][len + ZERO];
	int& cur = dp[pos][len + ZERO];
	cur = 0;
	for(int i = -1; i <= 1; ++ i)
		if(pos + len + d + i <= maxt && len + d + i > 0)
			cur = max(cur, dfs(pos + len + d + i, len + i));
	ans = max(ans, cur += cnt[pos]);
	return cur;
}
int main(){
	int i, t;
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &d);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		maxt = max(maxt, t);
		cnt[t] ++;
	}
	dfs(d, 0);
	printf("%d\n", ans);
	return 0;
}