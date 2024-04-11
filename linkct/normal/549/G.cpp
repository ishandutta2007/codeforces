#include <cstdio>
#include <algorithm>
using std :: sort;
const int MAXN = 200005;

int n, a[MAXN];

int main(){
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		a[i] += i;
	}
	sort(a + 1, a + 1 + n);
	for(i = 1; i <= n; ++ i) a[i] -= i;
	for(i = 2; i <= n; ++ i)
		if(a[i] < a[i - 1] || a[i] < 0){
			printf(":(\n");
			return 0;
		}
	for(i = 1; i <= n; ++ i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}