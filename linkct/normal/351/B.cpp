#include <cstdio>
const int MAXN = 3005;

int n, bit[MAXN];

int main(){
	int i, j, t, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		for(j = t; j <= n; j += j & -j) ans += bit[j];
		for(j = t; j; j -= j & -j) bit[j] ++;
	}
	printf("%d\n", ans / 2 * 4 + (ans & 1));
	return 0;
}