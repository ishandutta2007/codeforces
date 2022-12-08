#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long long a[3]; scanf ("%lld %lld %lld", a,a+1,a+2);
	puts("First"); fflush(stdout);

	long long u = 10;
	printf ("%lld\n", u); fflush(stdout);
	int r; scanf ("%d", &r);
	a[r - 1] += u;
	while (1){
		long long mn = min({ a[0], a[1], a[2] });
		long long mx = max({ a[0], a[1], a[2] });
		long long x = (a[0] + a[1] + a[2] - mn - mx) - mn;
		long long y = mx - mn;
		long long u = 2 * y - x;
		if (2 * x == y){
			printf ("%lld\n", x); fflush(stdout);
			break;
		}
		printf ("%lld\n", u); fflush(stdout);
		int r; scanf ("%d", &r);
		a[r - 1] += u;
	}

	return 0;
}