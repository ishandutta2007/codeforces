#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,s,e,x[11111],a[11111],b[11111],c[11111],d[11111];
long long res[11111],ans,cnt,mn,mni,cur;
long long go(int s,int e)
{
	long long res=abs(x[s]-x[e]);
	if (s<e) res=res+d[s]+a[e];
	else res=res+c[s]+b[e];
	return res;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&s,&e);
	for (int i=1;i<=n;i++) scanf("%I64d",&x[i]);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%I64d",&b[i]);
	for (int i=1;i<=n;i++) scanf("%I64d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%I64d",&d[i]);
	res[1]=s;res[2]=e;cnt=2;ans=go(s,e);
	for (int i=1;i<=n;i++)
	{
		if (i==s || i==e) continue;
		mn=1e18;
		for (int j=1;j<cnt;j++)
		{
			cur=go(res[j],i)+go(i,res[j+1])-go(res[j],res[j+1]);
			if (cur<mn) 
			{
				mn=cur;
				mni=j;
			}
		}
		ans+=mn;
		for (int j=cnt;j>mni;j--)
		res[j+1]=res[j];
		res[mni+1]=i;
		cnt++;
	}
	printf("%I64d\n",ans);
	return 0;
}