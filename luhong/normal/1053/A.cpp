#include <cstdio>
#include <algorithm>
int main()
{
	long long n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
	if(2 * n * m % k != 0) return puts("NO"), 0;
	long long s = 2 * n * m / k;
	long long X1, X2, Y1, Y2;
	X1 = n;
	Y2 = s / n;
	if(X1 * Y2 < s) Y2++;
	Y1 = 1;
	X2 = X1 * Y2 - s;
	if(Y2 <= m) printf("YES\n0 0\n%lld %lld\n%lld %lld\n", X1, Y1, X2, Y2);
	else puts("NO");
	return 0;
}

//x1y2-x2y1 = sx1(n)y2x1y2>=sy1=1, x2<=ny2>m