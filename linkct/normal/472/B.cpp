#include <cstdio>
#include <algorithm>
using std :: sort;

int n, k, f[2005], ans;

int main(){
	int i;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &f[i]);
	i = n;
	sort(f + 1, f + 1 + n);
	while(i > 0){
		ans += (f[i] << 1) - 2;
		i -= k;
	}
	printf("%d\n", ans);
	return 0;
}