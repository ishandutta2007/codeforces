#include<iostream>
#include<cstdio>
using namespace std;
long long a[111111],x,y,n,m,mx[111111],leng;
int main()
{
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		mx[i]=max(mx[i-1],a[i]);
	}
	scanf("%I64d",&m);
	while(m--)
	{
		scanf("%I64d%I64d",&x,&y);
		printf("%I64d\n",max(mx[x],leng));
		leng=max(mx[x],leng)+y;
	}
	return 0;
}