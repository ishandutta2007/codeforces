#include <cstdio>
const int MAXN = 105, MAXM = 1005;

int rk[MAXN], n, m;
double f[MAXN][MAXN * MAXM];

inline int max(int a, int b){return a > b ? a : b;}
int main(){
	int i, j, sum = 0;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &rk[i]);
		sum += rk[i];
	}
	if(m == 1){
		printf("1.000000000000\n");
		return 0;
	}
	for(i = 0; i <= m; ++ i) f[0][i] = double(m - 1);
	for(i = 1; i <= n; ++ i){
		for(j = 1; j <= i * m; ++ j){
			f[i][j] += f[i - 1][j - 1] - (j - rk[i] >= 0 ? f[i - 1][j - rk[i]] : 0.0);
			f[i][j] += (j - rk[i] - 1 >= 0 ? f[i - 1][j - rk[i] - 1] : 0.0) - (j - m - 1 >= 0 ? f[i - 1][j - m - 1] : 0.0);
			f[i][j] /= double(m - 1);
			f[i][j] += f[i][j - 1];
		}
		for(; j <= (i + 1) * m; ++ j)
			f[i][j] = f[i][j - 1];
	}
	printf("%.15f\n", f[n][sum - 1] + 1.0);
	return 0;
}