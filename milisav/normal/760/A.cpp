#include <iostream>
#include <cstdio>
using namespace std;
int m,d;
int n;
int main()
{
	scanf("%d %d",&m,&d);
	if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) n=31;
	else n=30;
	if(m==2) n=28;
	int c=1;
	n=n-(8-d);
	while(n>0)
	{
		n=n-7;
		c++;
	}
	printf("%d",c);
	return 0;
}