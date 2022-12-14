#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n;
int x[222222],y[222222],cntx,cnty,arrx[222222],arry[222222],tree[888888];
map<int,int> mpx,mpy;
vector<int> g[222222];
long long ans,cur;
void upd(int x,int l,int r,int node)
{
	if (l==r)
	{
		tree[node]=1;
		return;
	}
	int mid=(l+r)>>1;
	if (x>mid) upd(x,mid+1,r,(node<<1)|1);
	else upd(x,l,mid,node<<1);
	tree[node]=tree[node<<1]+tree[(node<<1)|1];
}
int query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	return query(beg,en,l,mid,node<<1)+query(beg,en,mid+1,r,(node<<1)|1);
}
long long get(int x,int y)
{
	int val=query(x+1,y-1,1,cntx,1);
	return 1ll*val*(val+1)/2;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for (int i=1;i<=n;i++)
	{
		arrx[i]=x[i];
		arry[i]=y[i];
	}
	sort(arrx+1,arrx+n+1);sort(arry+1,arry+n+1);
	cntx=unique(arrx+1,arrx+n+1)-arrx-1;
	cnty=unique(arry+1,arry+n+1)-arry-1;
	for (int i=1;i<=cntx;i++) mpx[arrx[i]]=i;
	for (int i=1;i<=cnty;i++) mpy[arry[i]]=i;
	for (int i=1;i<=n;i++)
	{
		x[i]=mpx[x[i]];
		y[i]=mpy[y[i]];
	}
	for (int i=1;i<=n;i++)
	{
		g[y[i]].push_back(x[i]);
	}
	for (int i=1;i<=cnty;i++)
	{
		g[i].push_back(0);g[i].push_back(cntx+1);
		sort(g[i].begin(),g[i].end());
	}
	for (int i=cnty;i>=1;i--)
	{
		for (int j=1;j<(int)g[i].size()-1;j++)
		{
			upd(g[i][j],1,cntx,1);
		}
		cur=get(0,cntx+1);
		for (int j=0;j<(int)g[i].size()-1;j++)
		{
			cur-=get(g[i][j],g[i][j+1]);
		}
		ans+=cur;
		
	}
	printf("%lld\n",ans);
	return Accepted;
}