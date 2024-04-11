#include<iostream>
#include<cstdio>
using namespace std;
int tree[444444],bit1[444444],bit2[444444],bit3[444444],n,m,a[444444],sz,l,r,dp[111111][2];
void update(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree[node]++;
		return;
	}
	int mid=(l+r)/2;
	update(beg,en,l,mid,node*2);
	update(beg,en,mid+1,r,node*2+1);
}
int query(int x)
{
	int pos=sz-1+x,res=0;
	while(pos>=1)
	{
		res+=tree[pos];
		pos/=2;
	}
	return res;
}
void update(int p,int x,int bit[])
{
	while(p<=sz)
	{
		bit[p]=max(bit[p],x);
		p+=p&(-p);
	}
}
int query(int p,int bit[])
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
	scanf("%d%d",&m,&n);
	sz=1<<17;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		update(l,r,1,sz,1);
	}
	for (int i=1;i<=n;i++) a[i]=query(i);
	for (int i=1;i<=n;i++)
	{
		dp[i][0]=query(a[i]+1,bit1)+1;
		dp[i][1]=max(query(sz-a[i],bit2),query(sz-a[i],bit3))+1;
		update(a[i]+1,dp[i][0],bit1);
		update(sz-a[i],dp[i][0],bit2);
		update(sz-a[i],dp[i][1],bit3);
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));
	return 0;
}