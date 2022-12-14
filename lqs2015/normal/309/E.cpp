#include<bits/stdc++.h>
using namespace std;
struct inter
{
	int l,r,id;
	bool operator < (const inter &u) const
	{
		if (r!=u.r) return r<u.r;
		return l<u.l;
	}
}a[2222];
int n,ans[2222],l,r,mid,far[2222],val[2222],pos;
bool used[2222];
bool intersect(int x,int y)
{
	return (max(a[x].l,a[y].l)<=min(a[x].r,a[y].r));
}
bool check(int mid)
{
	for (int i=1;i<=n;i++) far[i]=n;
	memset(used,0,sizeof(used));
	for (int i=1;i<=n;i++)
	{
		memset(val,0,sizeof(val));
		for (int j=1;j<=n;j++)
		{
			if (!used[j]) val[far[j]]++;
		}
		for (int j=1;j<=n;j++) val[j]+=val[j-1];
		for (int j=i;j<=n;j++)
		{
			if (val[j]>j-i+1) return 0;
			if (val[j]==j-i+1)
			{
				pos=j;
				break;
			}
		}
		for (int j=1;j<=n;j++)
		{
			if (!used[j] && far[j]<=pos) 
			{
				pos=j;
				break;
			}
		}
		used[pos]=1;ans[i]=a[pos].id;
		for (int j=1;j<=n;j++)
		{
			if (!used[j] && intersect(j,pos)) far[j]=min(far[j],i+mid);
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	l=1;r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	check(l);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}