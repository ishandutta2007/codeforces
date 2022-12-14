#include <cstdio>
const int MAXN = 100005;

int day[MAXN], height[MAXN], n, m;

inline int abs(int x){return x >= 0 ? x : -x;}
inline int max(int a, int b){return a > b ? a : b;}
int main(){
	int i, tmp, ans = 0;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &day[i], &height[i]);
		ans = max(ans, height[i]);
	}
	for(i = 2; i <= m; ++ i)
		if(day[i] - day[i - 1] < abs(height[i] - height[i - 1])){
			printf("IMPOSSIBLE\n");
			return 0;
		}
	ans = max(ans, day[1] - 1 + height[1]);
	ans = max(ans, n - day[m] + height[m]);
	for(i = 2; i <= m; ++ i){
		tmp = day[i] - day[i - 1] - abs(height[i] - height[i - 1]);
		ans = max(ans, max(height[i], height[i - 1]) + tmp / 2);
	}
	printf("%d\n", ans);
	return 0;
}