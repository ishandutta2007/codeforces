#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	long long  n, k;
	long long ans = 1;
	long long x;
	scanf("%I64d %I64d", &n,&k);
	if (k >1){
		x = n*(n - 1) / 2;
		ans += x;
	}
	if (k > 2){
		x = n*(n - 1)*(n - 2) / 3;
		ans += x;
	}
	if (k > 3){
		x = n*(n - 1)*(n - 2)*(n - 3) * 3 / 8;
		ans += x;
	}
	printf("%I64d\n", ans);

	return 0;
}