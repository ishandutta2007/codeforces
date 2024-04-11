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
	long long a[25];
	long long p2[25];
	f(i, 25)a[i] = 0;
	p2[0] = 1;
	f(i, 24)p2[i + 1] = p2[i] * 2;
	long long ans, x, n;
	scanf("%lld", &n);
	f(i, n) {
		scanf("%lld", &x);
		f(j, 25) {
			if (x % 2 == 1)a[j]++;
			x /= 2;
		}
	}
	ans = 0;
	f(i, n) {
		x = 0;
		f(j, 25) {
			if (i < a[j])x += p2[j];
		}
		ans += (x*x);
	}
	printf("%lld\n", ans);
	return 0;
}