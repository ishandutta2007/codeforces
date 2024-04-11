#include <stdio.h>

long long D[5000001];

int main()
{
	for (int i=1;i<=5000000;i++) D[i] = 1e18;
	D[1] = 0;

	for (int i=1;i<=5000000;i++){
		for (int j=i*2;j<=5000000;j+=i){
			int g = j / i;
			long long u = D[i] + (long long)j * (g - 1) / 2;
			if (D[j] > u)
				D[j] = u;
		}
	}

	long long t; int l,r;
	scanf ("%lld %d %d",&t,&l,&r);
	long long a = 0;
	for (int i=r;i>=l;i--){
		a = (a * t) % 1000000007;
		a = (a + D[i]) % 1000000007;
	}
	printf ("%lld\n",a);

	return 0;
}