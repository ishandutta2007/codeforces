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
#define N 301000
char a[N + 1];

long long sea(long long k,long long lim) {
	long long d = 1;
	while (lim < k-(2*d)) {
		if (a[k] == a[k - d] && a[k] == a[k - (2 * d)])return (k - (2 * d));
		d++;
	}
	return lim;
}


int main() {
	f(i, N + 1)a[i] = 0;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%s", a);
	n = strlen(a);
	x = -1;
	f(i, n) {
		y = sea(i, x);
		if (x != y) {
			ans += (y - x)*(n - i);
			x = y;
		}
	}

	printf("%I64d\n", ans);


	return 0;
}