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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000


int main() {
	long long a[N];
	long long b[N];
	f(i, N)a[i] = 0;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld %lld", &k, &n);
	f(i, n) {
		scanf("%lld", &a[i]);
	}
	f(i, n) {
		if ((i + a[i]) <= k)b[i] = i + 1;
		else {
			printf("-1\n");
			return 0;
		}
	}
	for (long long i = n - 1; i >= 0; i--) {
		if ((b[i] + a[i] - 1) < k) {
			b[i] = k - a[i] + 1;
			k = b[i] - 1;
		}
else break;
	}
	if (b[0] > 1) {
		printf("-1\n");
		return 0;
	}
	f(i, n-1) {
		printf("%lld ", b[i]);
	}
	printf("%lld\n", b[n - 1]);
	return 0;
}