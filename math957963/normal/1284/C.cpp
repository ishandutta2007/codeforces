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
#define N 300000

int main() {
	long long a[N];
	long long x, y, z;
	long long s, ans;
	scanf("%I64d %I64d", &x, &y);
	a[0] = 1;
	f(i, N - 1) {
		a[i + 1] = (a[i] * (i + 1)) % y;
	}
	ans = 0;
	f(i, x) {
		s = a[i + 1] * a[x - i];
		s = s % y;
		s = (s*(x - i)) % y;
		ans = (ans + s) % y;
	}
	printf("%I64d\n", ans);


	return 0;
}