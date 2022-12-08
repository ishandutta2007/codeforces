#include <stdio.h>

int gcd(int a, int b)
{
	return b ? gcd(b,a%b) : a;
}

int main()
{
	int n,m,k;
	scanf ("%d %d %d",&n,&m,&k);
	if (k % 2){
		int ng = gcd(n,k);
		int mg = gcd(m,k/ng);
		if (k / ng / mg == 1){
			if (n / ng * 2 < n) n *= 2;
			else m *= 2;
			puts("YES");
			printf ("0 0\n");
			printf ("%d 0\n",n/ng);
			printf ("0 %d\n",m/mg);
		}
		else puts("NO");
	}
	else{
		k /= 2;
		int ng = gcd(n,k);
		int mg = gcd(m,k/ng);
		if (k / ng / mg == 1){
			puts("YES");
			printf ("0 0\n");
			printf ("%d 0\n",n/ng);
			printf ("0 %d\n",m/mg);
		}
		else puts("NO");
	}
	return 0;
}