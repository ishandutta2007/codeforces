#include <cstdio>
#include <cstring>
const int MAXN = 105;

int dp[MAXN][MAXN][MAXN], path[MAXN][MAXN][MAXN], n1, n2, n3, nxt[MAXN][30], f[MAXN];
char str1[MAXN], str2[MAXN], vir[MAXN];

void getPath(int i, int j, int k){
	int cur = path[i][j][k];
	if(!cur) return;
	if(cur == 1) getPath(i - 1, j, k);
	else if(cur == 2) getPath(i, j - 1, k);
	else{
		getPath(i - 1, j - 1, - cur - 1);
		putchar(str1[i]);
	}
}
int main(){
	int i, j, k, *now, *tr, ans = 0, p1, p2, p3;
	scanf("%s%s%s", str1 + 1, str2 + 1, vir + 1);
	n1 = strlen(str1 + 1), n2 = strlen(str2 + 1), n3 = strlen(vir + 1);
	for(i = 1; i <= n3; ++ i) nxt[i - 1][vir[i] - 'A'] = i;
	for(i = 1; i < n3; ++ i)
		for(j = 0; j < 26; ++ j)
			if(nxt[i][j]) f[nxt[i][j]] = nxt[f[i]][j];
			else nxt[i][j] = nxt[f[i]][j];
	for(i = 1; i <= n1; ++ i)
		for(j = 1; j <= n2; ++ j){
			now = dp[i][j], tr = path[i][j];
			for(k = 0; k < n3; ++ k){
				if(dp[i - 1][j][k] >= now[k]){
					now[k] = dp[i - 1][j][k];
					tr[k] = 1;
				}
				if(dp[i][j - 1][k] >= now[k]){
					now[k] = dp[i][j - 1][k];
					tr[k] = 2;
				}
				if(str1[i] == str2[j] && now[nxt[k][str1[i] - 'A']] <= dp[i - 1][j - 1][k] + 1){
					now[nxt[k][str1[i] - 'A']] = dp[i - 1][j - 1][k] + 1;
					tr[nxt[k][str1[i] - 'A']] = - k - 1;
				}
			}
			for(k = 0; k < n3; ++ k)
				if(now[k] > ans){
					ans = now[k];
					p1 = i, p2 = j, p3 = k;
				}
		}
	if(ans == 0) printf("0");
	else getPath(p1, p2, p3);
	putchar('\n');
	return 0;
}