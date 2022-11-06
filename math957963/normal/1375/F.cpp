#pragma GCC optimize("O3")
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
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	long long a[3];
	long long n, k, kk;
	long long x, y, z;
	scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);
	printf("First\n");
	fflush(stdout);
	printf("10000000000\n");
	fflush(stdout);
	scanf("%lld", &k);
	if (k < 1)return 0;
	a[k - 1] += 10000000000;
	x = 0;
	f(i, 3) {
		if (a[i] >= 10000000000)x += a[i] * 2;
		else x -= a[i];
	}
	printf("%lld\n", x);
	fflush(stdout);
	scanf("%lld", &kk);
	if (kk < 1)return 0;
	a[kk - 1] += x;
	y = a[kk - 1] - a[k - 1];
	printf("%lld\n", y);
	fflush(stdout);
	scanf("%lld", &kk);
	return 0;
}