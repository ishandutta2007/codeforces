#include <cstdio>
#include <cstring>
#define MAXN 200005
#define MOD 1000000007
//f[i]: number of selections with i red blocks
int f[2][MAXN], r, g;
bool vis[2][MAXN];
int main(){
	int now = 1, i, j, ans = 0, cnt = 0;
	bool sign = true;
	scanf("%d%d", &r, &g);
	f[0][r] = 1;
	vis[0][r] = true;
	for(i = 1; sign; ++ i){
		memset(f[now], 0, sizeof(f[now]));
		memset(vis[now], false, sizeof(vis[now]));
		sign = false;
		for(j = 0; j <= r; ++ j){
			if(j + i <= r && vis[now ^ 1][j + i]) f[now][j] = (f[now][j] + f[now ^ 1][j + i]) % MOD, vis[now][j] = sign = true;
			if(g - (cnt - (r - j)) >= i && vis[now ^ 1][j]) f[now][j] = (f[now][j] + f[now ^ 1][j]) % MOD, vis[now][j] = sign = true;
		}
		cnt += i;
		now ^= 1;
	}
	for(i = 0; i <= r; ++ i)
		ans = (ans + f[now][i]) % MOD;
	printf("%d\n", ans);
	return 0;
}