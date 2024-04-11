#include<bits/stdc++.h>
using namespace std;
int k,n,ls=1,mx=0,r,a[100005],t[100005];
int main()
{
	scanf("%d%d",&n,&k),ls=1;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) continue;
		else if(a[i]==a[ls-1]) t[a[ls]]+=2,ls=i;
		else t[a[ls]]++,ls=i;
	}
	t[a[n]]++,mx=0;
	for(int i=1;i<=k;i++) if(mx<t[i]) mx=t[i],r=i;
	return printf("%d\n",r),0;
}