#include <cstdio>
#include <cstdlib>

long long Max(long long a, long long b) {return a > b ? a : b;}

long long Min(long long a, long long b) {return a < b ? a : b;}

int main()
{
	srand(98432156);
	long long n; int k; 
	scanf("%lld%d", &n, &k);
	long long l = 1, r = n;
	for(int i = 1; i <= 4500; i++)
	{
		if(r - l + 1 <= 4 * k + 10)
		{
			int R = rand() % (r - l + 1);
			printf("%lld %lld\n", l + R, l + R);
			fflush(stdout);
			char c[4];
			scanf("%s", c);
			if(c[0] == 'Y') return 0;
		}
		else
		{
			long long mid = l + r >> 1;
			printf("%lld %lld\n", l, mid);
			fflush(stdout);
			char c[4];
			scanf("%s", c);
			if(c[0] == 'Y') r = mid;
			else l = mid + 1;
		}
		l = Max(1, l - k);
		r = Min(r + k, n);
	}
	return 0;
 }