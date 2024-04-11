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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main() {
	long long x, y, z;
	long long s, ans;
	scanf("%lld %lld %lld", &x, &y, &z);
	z *= 2;
	s = x % y;
	s = (y - s) % y;
	s += (2 * x);
	ans = z / s;
	z -= (ans*s);
	s = (x + y - 1) / y;
	s *= y;
	ans *= s;
	if (z <= (2 * x)) {
		ans += (z / 2);
		if (z % 2 == 1) {
			printf("%lld.5", ans);
		}
		else printf("%lld\n", ans);
	}
	else {
		ans += (z - x);
		printf("%lld\n", ans);
	}

	return 0;
}