#include<bits/stdc++.h>
using namespace std;
int n,k,num[222222];
long long a[222222],b[222222],l,r,mid,need,ans,tim,cur;
bool f;
bool check()
{
	need=0;
	for (int i=1;i<=n;i++)
	{
		ans=a[i]-b[i]*k;
		if (ans>=0) continue;
		ans=-ans;
		if ((ans+mid-1)/mid>k) return 0;
	}
	for (int i=1;i<=n;i++)
	{
		ans=a[i]-b[i]*k;
		if (ans>=0) continue;
		ans=-ans;
		need+=((ans+mid-1)/mid);
	}
	if (need>k) return 0;
	memset(num,0,sizeof(num));
	for (int i=1;i<=n;i++)
	{
		ans=a[i];tim=0;
		while(tim<=k)
		{
			tim+=(ans/b[i]);
			ans%=b[i];
			if (tim>=k) break;
			cur=tim+1;
			ans-=b[i];
			while(ans<0 && cur>=1) 
			{
				ans+=mid;
				num[cur]++;
				cur--;
			} 
			tim++;
		}
	}
	for (int i=1;i<=k;i++) num[i]+=num[i-1];
	for (int i=1;i<=k;i++)
	{
		if (num[i]>i) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&k);k--;
	if (!k)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for (int i=1;i<=n;i++)
	{
		if (a[i]-b[i]*k<0) f=1;
	}
	if (!f)
	{
		printf("0\n");
		return 0;
	}
	l=1;r=1e18;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (check()) r=mid-1;
		else l=mid+1;
	}
	if (l>5e17) printf("-1\n");
	else printf("%lld\n",l);
	return 0;
}