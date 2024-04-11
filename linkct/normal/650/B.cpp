#include <cstdio>
const int MAXN = 500005;

int n, a, b, T, rcost[MAXN], base, rot[MAXN];
char buf[MAXN];

inline int min(int a, int b){return a > b ? b : a;}
inline int max(int a, int b){return a > b ? a : b;}
int getCost(int i, int j){
	return base + rcost[j] + n + 1 - j + i + (min(i - 1, n + 1 - j) + n - j + i) * a;
}
int main(){
	int i, j, ans;
	scanf("%d%d%d%d%s", &n, &a, &b, &T, buf + 1);
	for(i = 1; i <= n; ++ i) rot[i] = int(buf[i] == 'w');
	for(i = n; i; -- i) rcost[i] = rcost[i + 1] + rot[i] * b;
	base = rot[1] * b;
	for(j = n + 1; j > 2 && getCost(1, j - 1) <= T; -- j) ;
	if(getCost(1, j) > T){
		printf("0\n");
		return 0;
	}
	ans = n + 1 - j + 1;
	if(ans == n){
		printf("%d\n", n);
		return 0;
	}
	for(i = 2; i <= n; ++ i){
		base += rot[i] * b;
		while(j <= n && getCost(i, j) > T) ++ j;
		if(getCost(i, j) > T) break;
		ans = max(ans, n + 1 - j + i);
	}
	printf("%d\n", ans);
	return 0;
}