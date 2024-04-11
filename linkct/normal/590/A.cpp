#include <cstdio>
const int MAXN = 500005;

int n, a[MAXN];

inline int max(int a, int b){return a > b ? a : b;}
int main(){
	int i, j, k, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	for(i = 1, j = 2; j <= n; ++ j){
		if(a[j] == a[j - 1]){//[i, j - 1]
			if(j - i <= 2){
				i = j;
				continue;
			}
			if((j - i) & 1){
				ans = max(ans, (j - i) >> 1);
				for(k = i + 1; k < j; ++ k) a[k] = a[i];
			}else{
				ans = max(ans, ((j - i) >> 1) - 1);
				for(k = i + 1; k < i + ((j - i) >> 1); ++ k) a[k] = a[i];
				for(; k < j; ++ k) a[k] = a[j - 1];
			}
			i = j;
		}
	}
	if(j - i > 2){
		if((j - i) & 1){
			ans = max(ans, (j - i) >> 1);
			for(k = i + 1; k < j; ++ k) a[k] = a[i];
		}else{
			ans = max(ans, ((j - i) >> 1) - 1);
			for(k = i + 1; k < i + ((j - i) >> 1); ++ k) a[k] = a[i];
			for(; k < j; ++ k) a[k] = a[j - 1];
		}
	}
	printf("%d\n", ans);
	for(i = 1; i <= n; ++ i) printf("%d ", a[i]);
	printf("\n");
	return 0;
}