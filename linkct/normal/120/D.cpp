#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 55;

int n, m, pf[MAXN][MAXN], res[5];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, tmp[5], ans = 0;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j){
			scanf("%d", &pf[i][j]);
			pf[i][j] -= pf[i - 1][j - 1] - pf[i - 1][j] - pf[i][j - 1];
		}
	scanf("%d%d%d", &res[1], &res[2], &res[3]);
	sort(res + 1, res + 4);
	for(i = 1; i < n; ++ i)
		for(j = i + 1; j < n; ++ j){
			tmp[1] = pf[i][m];
			tmp[2] = pf[j][m] - pf[i][m];
			tmp[3] = pf[n][m] - pf[j][m];
			sort(tmp + 1, tmp + 4);
			if(res[1] == tmp[1] && res[2] == tmp[2] && res[3] == tmp[3])
				++ ans;
		}
	for(i = 1; i < m; ++ i)
		for(j = i + 1; j < m; ++ j){
			tmp[1] = pf[n][i];
			tmp[2] = pf[n][j] - pf[n][i];
			tmp[3] = pf[n][m] - pf[n][j];
			sort(tmp + 1, tmp + 4);
			if(res[1] == tmp[1] && res[2] == tmp[2] && res[3] == tmp[3])
				++ ans;
		}
	printf("%d\n", ans);
	return 0;
}