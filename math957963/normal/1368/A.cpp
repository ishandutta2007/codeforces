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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000


int main() {
	long long a, b, n, t, ans;
	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld %lld %lld", &a, &b, &n);
		ans = 0;
		while ((a <= n) && (b <= n)) {
			if (a > b)swap(a, b);
			a += b;
			ans++;
		}
		printf("%lld\n", ans);
	}

	return 0;
}