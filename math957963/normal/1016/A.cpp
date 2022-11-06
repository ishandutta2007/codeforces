#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<long long(n);i++)
#define N 200000


int main(){
	long long a[N+1];
	long long n, k;
	long long s, ans;
	scanf("%I64d %I64d", &n,&k);
	a[0] = 0;
	f(i, n){
		scanf("%I64d", &s);
		a[i + 1] = a[i] + s;
		ans = (a[i + 1] / k) - (a[i] / k);
		printf("%I64d", ans);
		if (i<(n - 1))	printf(" ");
		else 	printf("\n");
	}

	return 0;
}