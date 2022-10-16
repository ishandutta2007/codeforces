#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 305;
int n, K, d[N][N];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &d[i][j]);
	scanf("%d", &K);
	for (int k = 1; k <= K; k++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], min(d[i][v] + w + d[u][j], d[i][u] + w + d[v][j]));
			}
		}
		LL res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++) 
				res += d[i][j];
		printf("%lld ", res);
	}
	return 0;
}