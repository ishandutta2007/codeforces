#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int tree1[2222222],tree2[2222222],in[555555],out[555555],x,y,cnt,sz,tp,res1,res2,n,q;
vector<int> g[555555];
void dfs(int i,int fa)
{
	in[i]=++cnt;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
	out[i]=cnt;
}
void update1(int beg,int en,int l,int r,int node,int x)
{
	if (l>=beg && r<=en)
	{
		tree1[node]=x;
		return;
	}
	if (l>en || r<beg) return;
	int mid=(l+r)/2;
	update1(beg,en,l,mid,node*2,x);
	update1(beg,en,mid+1,r,node*2+1,x);
}
void update2(int i,int x)
{
	int id=sz+i-1;
	while(id)
	{
		tree2[id]=x;
		id/=2;
	}
}
int query1(int i)
{
	int id=sz+i-1,res=0;
	while(id)
	{
		res=max(res,tree1[id]);
		id/=2;
	}
	return res;
}
int query2(int beg,int en,int l,int r,int node)
{
	if (l>=beg && r<=en) return tree2[node];
	if (l>en || r<beg) return 0;
	int mid=(l+r)/2;
	return max(query2(beg,en,l,mid,node*2),query2(beg,en,mid+1,r,node*2+1));
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0);
	sz=1;
	while(sz<n) sz*=2;
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&tp,&x);
		if (tp==1)
		{
			update1(in[x],out[x],1,sz,1,i);
		}
		else if (tp==2)
		{
			update2(in[x],i);
		}
		else 
		{
			res1=query1(in[x]);
			res2=query2(in[x],out[x],1,sz,1);
			if (!res1 && !res2) printf("0\n");
			else if (res1>res2) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}