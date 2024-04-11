#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	int k;if(b%c==0)k=b/c;else k=b/c+1;
	int s=k*a;if(s%d==0)printf("%d",s/d);else printf("%d",s/d+1);
	return 0;
 }