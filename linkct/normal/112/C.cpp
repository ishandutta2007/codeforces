#include <cstdio>
#include <cassert>
typedef long long int LL;

int main(){
	int n, y; LL x;
	assert(scanf("%d%I64d%d", &n, &x, &y) == 3);
	assert(n >= 1 && n <= 100000 && x >= 1 && x <= 1000000000000LL && y >= 1 && y <= 1000000);
	if(y < n || LL(y - n + 1) * (y - n + 1) + n - 1 < x)
		printf("-1\n");
	else{
		printf("%d\n", y - n + 1);
		while(-- n) printf("1\n");
	} return 0;
}