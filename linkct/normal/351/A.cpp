#include <cstdio>

inline int min(int a, int b){return a > b ? b : a;}
inline int max(int a, int b){return a > b ? a : b;}
inline int abs(int x){return x >= 0 ? x : -x;}
int main(){
	int n, i, t, sum = 0, cnt = 0, ans = 0x3f3f3f3f, l, r;
	scanf("%d", &n); n <<= 1;
	for(i = 1; i <= n; ++ i){
		scanf("%*d.%d", &t);
		sum += t;
		if(!t) cnt ++;
	}
	r = min(n - cnt, n >> 1);
	l = max((n >> 1) - cnt, 0);
	for(i = l; i <= r; ++ i) ans = min(ans, abs(sum - i * 1000));
	printf("%.3f\n", ans / 1000.0);
	return 0;
}