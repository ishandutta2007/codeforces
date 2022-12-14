#include <cstdio>
#include <cstring>
#define MAXN 5005
const int INF = 0x3f3f3f3f;

char str[MAXN], pattern[505];
int lens, lenp, a[MAXN], dp[MAXN][MAXN];

inline int max(int a, int b){return a > b ? a : b;}
int main(){
	int i, j, k;
	scanf("%s%s", str, pattern);
	lens = strlen(str), lenp = strlen(pattern);
	for(i = 0; i < lens; ++ i){
		for(j = i, k = 0; j < lens; ++ j)
			if(str[j] == pattern[k]){
				k ++;
				if(k == lenp) break;
			}
		if(k == lenp) a[i] = j - i + 1;
		else a[i] = INF;
	}
	for(i = 0; i < lens; ++ i)
		for(j = 0; j <= i; ++ j){
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			if(a[i] != INF) dp[i + a[i]][j + a[i] - lenp] = max(dp[i + a[i]][j + a[i] - lenp], dp[i][j] + 1);
		}
	for(i = 0; i <= lens; ++ i)
		printf("%d%c", dp[lens][i], i == lens ? '\n' : ' ');
	return 0;
}