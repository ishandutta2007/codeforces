#include <bits\stdc++.h>
using namespace std;
long long int n,k;
long long int l;
long long int g;
void divisors()
{
	long long int m=n;
	long long int x,y;
	for(long long int i=2;i*i<=m;i++)
	{
		if(m%i==0)
		{
			x=i;
			y=m/i;
			if(x<=l && x>g) g=x;
			if(y<=l && y>g) g=y;
		}
	}
}
int main()
{
	scanf("%lld %lld",&n,&k);
	if(k>=1000000 || k*(k+1)>2*n)
	{
		printf("-1");
		return 0;
	}
	l=k*(k+1);
	l=l/2;
	l=n/l;
	g=1;
	divisors();
	long long int m=n;
	m=m/g;
	for(long long int i=1;i<k;i++)
	{
		printf("%lld ",i*g);
		m=m-i;
	}
	printf("%lld ",m*g);
	return 0;
}