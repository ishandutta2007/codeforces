#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a[111111],n,x,cur,ans1,ans2,y;
int main()
{
	ans1=ans2=-1e9;
	scanf("%lld%lld",&n,&x);
	for (int i=1;i<n;i++)
	{
		scanf("%lld",&y);
		a[i]=abs(x-y);
		x=y;
	}
	cur=a[1];
	for (int i=2;i<n;i+=2)
	{
		ans1=max(ans1,cur);
		cur+=(a[i+1]-a[i]);
		if (cur<a[i+1]) cur=a[i+1];
	}
	ans1=max(ans1,cur);
	cur=a[2];
	for (int i=3;i<n;i+=2)
	{
		ans2=max(ans2,cur);
		cur+=(a[i+1]-a[i]);
		if (cur<a[i+1]) cur=a[i+1];
	}
	ans2=max(ans2,cur);
	printf("%lld\n",max(ans1,ans2));
	return 0;
}