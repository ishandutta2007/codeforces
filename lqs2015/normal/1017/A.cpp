#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,c,d,sum,ans,cur;
int main()
{
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	sum=a+b+c+d;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		cur=a+b+c+d;
		if (cur>sum) ans++;
	}
	printf("%d\n",ans+1);
	return 0;
 }