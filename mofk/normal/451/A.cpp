#include<stdio.h>
int main(void)
{
	int n,m,t;
	scanf("%d%d",&n,&m);
	if(m<n){t=m;m=n;n=t;}
	if(n%2==0) printf("Malvika");
	else printf("Akshat");
}