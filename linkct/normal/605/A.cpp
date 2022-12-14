#include <cstdio>
const int MAXN = 100005;

int n, f[MAXN];

int main(){
	int i, p, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &p);
		f[p] = f[p - 1] + 1;
		if(f[p] > ans) ans = f[p];
	}
	printf("%d\n", n - ans);
	return 0;
}