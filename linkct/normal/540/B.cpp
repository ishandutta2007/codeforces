#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, p, x, y, a[1005], sum, pos;

int main(){
	int i, k_;
	scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
	k_ = k;
	for(i = 1; i <= k; ++ i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + 1 + k);
	pos = lower_bound(a + 1, a + 1 + k, y) - a;
	if(k == 0 || a[pos] >= y) pos --;
	if(pos > n / 2){
		printf("-1\n");
		return 0;
	}
	for(i = pos + 1; i <= n / 2 && k < n; ++ i)
		a[++ k] = 1, sum ++;
	sum += (n - k) * y;
	if(sum <= x){
		for(i = k_ + 1; i <= k; ++ i) printf("1 ");
		for(; i <= n; ++ i) printf("%d ", y);
		printf("\n");
	}else printf("-1\n");
	return 0;
}