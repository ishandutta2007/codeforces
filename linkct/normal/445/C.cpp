#include <cstdio>
const int MAX = 505;

int n, m, val[MAX];

inline double max(double a, double b){return a > b ? a : b;}
int main(){
	int i, a, b, c; double ans = 0.000;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &val[i]);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &a, &b, &c);
		ans = max(ans, 1.0 * (val[a] + val[b]) / c);
	}
	printf("%.15f\n", ans);
	return 0;
}