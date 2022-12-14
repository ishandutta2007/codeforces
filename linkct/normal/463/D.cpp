#include <cstdio>
#define MAX 1005

struct data{
	int d[6];
}input[MAX];
int n, k, pos[6][MAX], dp[MAX], map[MAX];

inline int max(int a, int b){return a > b ? a : b;}
inline bool check(int now, int aft){
	for(int i = 2; i <= k; ++ i)
		if(pos[i][now] > pos[i][aft])
			return false;
	return true;
}
int main(){
	int i, j, ans = 1;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= k; ++ i)
		for(j = 1; j <= n; ++ j)
			scanf("%d", &input[j].d[i]);
	for(i = 1; i <= n; ++ i)
		map[input[i].d[1]] = i;
	for(i = 2; i <= k; ++ i)
		for(j = 1; j <= n; ++ j)
			input[j].d[i] = map[input[j].d[i]];
	for(i = 2; i <= k; ++ i)
		for(j = 1; j <= n; ++ j)
			pos[i][input[j].d[i]] = j;
	for(i = n; i >= 1; -- i){
		dp[i] = 1;
		for(j = i + 1; j <= n; ++ j)
			if(check(i, j))
				dp[i] = max(dp[i], dp[j] + 1);
	}
	for(i = 1; i < n; ++ i)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}