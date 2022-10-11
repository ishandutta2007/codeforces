#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
int dp[20][200005],ss[200005],dep[200005],pos[200005],cnum[200005],arr[200005],idx[200005],head[200005],tree[800005],n,cn,num;
vector<pair<int,pair<int,int> > > v[200005];
void build(int node,int start,int end)
{
    if (start==end)
    tree[node]=arr[start];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}
int query(int node,int start,int end,int l,int r)
{
    if (r<start || end<l || r<l)
    return -(1<<29);
    if (l<=start && end<=r)
    return tree[node];
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    return max(p1,p2);
}
void dfs(int node,int pnode,int d)
{
	ss[node]=1;
	dp[0][node]=pnode;
	dep[node]=d;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i].first!=pnode)
		dfs(v[node][i].first,node,d+1),ss[node]+=ss[v[node][i].first];
	}
}
void HLD(int node,int pnode,int cost)
{
	if (head[num]==-1)
	head[num]=node;
	cnum[node]=num;
	idx[node]=cn;
	arr[cn++]=cost;
	int ind=-1;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i].first!=pnode && (ind==-1 || ss[v[node][ind].first]<ss[v[node][i].first]))
		ind=i;
	}
	if (ind!=-1)
	HLD(v[node][ind].first,node,v[node][ind].second.first);
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i].first!=pnode && i!=ind)
		{
			num++;
			HLD(v[node][i].first,node,v[node][i].second.first);
		}
	}
}
void preprocess()
{
	memset(dp,-1,sizeof(dp));
	dfs(1,-1,1);
	for (int x=1;x<20;x++)
	{
		for (int i=1;i<=n;i++)
		{
			if (dp[x-1][i]!=-1)
			dp[x][i]=dp[x-1][dp[x-1][i]];
		}
	}
	HLD(1,-1,-1);
	build(1,0,cn-1);
}
int lca(int u,int v)
{
	if (dep[u]<dep[v])
	swap(u,v);
	int dist=dep[u]-dep[v];
	for (int i=0;i<20;i++)
	{
		if ((dist>>i)&1)
		u=dp[i][u];
	}
	if (u==v)
	return u;
	for (int i=19;i>=0;i--)
	{
		if (dp[i][u]!=dp[i][v])
		{
			v=dp[i][v];
			u=dp[i][u];
		}
	}
	return dp[0][u];
}
int go(int u,int v)
{
	int ans=-1;
	while (cnum[u]!=cnum[v])
	{
		ans=max(ans,query(1,0,cn-1,idx[head[cnum[u]]],idx[u]));
		u=dp[0][head[cnum[u]]];
	}
	return max(ans,query(1,0,cn-1,idx[v]+1,idx[u]));
}
int answer(int u,int v)
{
	int l=lca(u,v);
	return max(go(u,l),go(v,l));
}
vector<pair<int,int> > v2,v3;
int find(int x)
{
	if (pos[x]!=x)
	pos[x]=find(pos[x]);
	return pos[x];
}
bool Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	return 0;
	else
	{
		pos[x]=y;
		return 1;
	}
}
long long ans[200005];
int main()
{
	memset(head,-1,sizeof(head));
	int m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	pos[i]=i;
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v2.push_back(make_pair(c,i));
		v3.push_back(make_pair(a,b));
	}
	sort(v2.begin(),v2.end());
	long long w=0;
	for (int i=0;i<m;i++)
	{
		int idx=v2[i].second;
		if (Union(v3[idx].first,v3[idx].second))
		{
			w+=v2[i].first;
			ans[idx]=1;
			v[v3[idx].first].push_back(make_pair(v3[idx].second,make_pair(v2[i].first,i)));
			v[v3[idx].second].push_back(make_pair(v3[idx].first,make_pair(v2[i].first,i)));
		}
	}
	dfs(1,-1,1);
	preprocess();
	for (int i=0;i<m;i++)
	{
		int idx=v2[i].second;
		if (ans[idx])
		ans[idx]=w;
		else
		{
			int m=answer(v3[idx].first,v3[idx].second);
			ans[idx]=w-m+v2[i].first;
		}
	}
	for (int i=0;i<m;i++)
	cout << ans[i] << endl;
}