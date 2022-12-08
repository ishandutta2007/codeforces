#include <stdio.h>

int main()
{
	int T; scanf ("%d", &T); while (T--){
		long long a, b, n; scanf ("%lld %lld %lld", &a, &b, &n);
		int c = 0;
		while (a <= n && b <= n){
			if (a < b) a += b;
			else b += a;
			c++;
		}
		printf ("%d\n", c);
	}
	return 0;
}