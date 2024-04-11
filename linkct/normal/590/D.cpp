#include <cstdio>
#include <cstring>
const int MAXN = 153, MAXS = MAXN * MAXN / 4 + MAXN / 2 + 15;

int dp1[MAXN][MAXS], dp2[MAXN][MAXS];
int n, K, s, sum, seq[MAXN];

inline void update1(int &a, int b){if(a < b) a = b;}
inline void update2(int &a, int b){if(a > b) a = b;}
inline int min(int a, int b){return a > b ? b : a;}
int main(){
	int i, j, k, ans = 0x3f3f3f3f;
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, 0x3f, sizeof(dp2));
	scanf("%d%d%d", &n, &K, &s);
	s = min(s, n * n / 4 + n / 2 + 15);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i]);
		if(i <= K) sum += seq[i];
	}
	dp1[0][0] = 0;
	for(i = 1; i <= K; ++ i)
		for(j = i; j >= 1; -- j)
			for(k = s; k >= K - i; -- k){
				if(dp1[j - 1][k - (K - i)] != -1)
					update1(dp1[j][k], dp1[j - 1][k - (K - i)] + seq[i]);
			}
	for(j = 0; j <= K; ++ j)
		for(k = 1; k <= s; ++ k)
			update1(dp1[j][k], dp1[j][k - 1]);
	dp2[0][0] = 0;
	for(i = K + 1; i <= n; ++ i)
		for(j = i - K; j >= 1; -- j)
			for(k = s; k >= i - K; -- k)
				update2(dp2[j][k], dp2[j - 1][k - (i - K)] + seq[i]);
	for(i = 0; i <= min(K, n - K); ++ i)
		for(j = 0; j <= s; ++ j)
			if(dp1[i][s - j] != -1)
				update2(ans, dp2[i][j] - dp1[i][s - j]);
	printf("%d\n", ans + sum);
	return 0;
}