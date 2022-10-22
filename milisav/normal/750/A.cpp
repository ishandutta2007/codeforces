#include <iostream>
#include <cstdio>
int k;
int n;
int main() 
{
	scanf("%d %d",&n,&k);
	int m=0;
	int r=0;
	while(r+k<=240 && m<=n)
	{
		m++;
		r+=5*m;
	}
	if(r+k>240) 
	{
		r-=5*m;
		m--;
	}
	if(m>n) m--;
	printf("%d",m);
	return 0;
}