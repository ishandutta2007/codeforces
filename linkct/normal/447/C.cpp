#include <cstdio>
#define MAXN 100005

int seq[MAXN], left[MAXN], right[MAXN], n;

inline int max(int a, int b){return a > b ? a : b;}
int main(){
	int i, ans = 1;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &seq[i]);
	left[1] = 1;
	for(i = 2; i <= n; ++ i){
		left[i] = (seq[i] > seq[i - 1] ? left[i - 1] + 1 : 1);
		ans = max(ans, left[i]);
	}
	right[n] = 1;
	for(i = n - 1; i; -- i){
		right[i] = (seq[i] < seq[i + 1] ? right[i + 1] + 1 : 1);
		ans = max(ans, right[i]);
	}
	ans = max(ans, right[2] + 1);
	ans = max(ans, left[n - 1] + 1);
	for(i = 2; i <= n; ++ i)
		if(seq[i - 1] < seq[i + 1] - 1)
			ans = max(ans, left[i - 1] + right[i + 1] + 1);
		else ans = max(ans, max(left[i - 1] + 1, right[i + 1] + 1));
	printf("%d\n", ans);
	return 0;
}