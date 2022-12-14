#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[222222],b[222222],cnt,bit[444444],sz,pre[222222],suf[222222],ans,c[222222];
map<int,int> mp;
void update(int p,int x)
{
	while(p<=sz)
	{
		bit[p]=max(bit[p],x);
		p+=p&(-p);
	}
}
int query(int p)
{
	int res=0;
	while(p>=1)
	{
		res=max(res,bit[p]);
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]-=i;
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	cnt=unique(a+1,a+n+1)-a-1;
	for (int i=1;i<=cnt;i++) 
	{
		mp[a[i]]=i;
	}
	sz=1;
	while(sz<cnt) sz*=2;
	for (int i=1;i<=n;i++) 
	{
		c[i]=b[i];
		b[i]=mp[b[i]];	
	}
	for (int i=1;i<=n;i++)
	{
		pre[i]=query(b[i])+1;
		update(b[i],pre[i]);
	}
	memset(bit,0,sizeof(bit));
	for (int i=n;i>=1;i--)
	{
		suf[i]=query(sz-b[i]+1)+1;
		update(sz-b[i]+1,suf[i]);
	}
	memset(bit,0,sizeof(bit));
	for (int i=n;i>=1;i--)
	{
		int x=lower_bound(a+1,a+cnt+1,c[i]-1)-a;
		ans=max(ans,max(pre[i],pre[i]+query(sz-x+1)+1));
		if (i<n) update(sz-b[i+1]+1,suf[i+1]);
	}
	if (ans>n) ans=n;
	printf("%d\n",n-ans);
	return 0;
}