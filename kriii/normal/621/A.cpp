#include <stdio.h>

int main()
{
	int N; long long sum = 0, min = 1e18;
	scanf ("%d",&N); while (N--){
		long long x; scanf ("%lld",&x);
		sum += x;
		if (x % 2 && min > x) min = x;
	}
	if (sum % 2) sum -= min;
	printf ("%lld\n",sum);
	return 0;
}