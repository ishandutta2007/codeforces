#include <bits/stdc++.h>
using namespace std;
#define MX 200000
#define sz 40000000
#define mod 1000000007
vector<pair<int,int> > v[100005];
int pw[MX+5],cn,tree[sz],h[sz],lc[sz],rc[sz],dist[100005],par[100005];
void push(int node,int st,int en)
{
	if (st!=en)
	{
		if (!lc[node])
		lc[node]=++cn;
		if (!rc[node])
		rc[node]=++cn;
	}
}
bool update(int node,int node2,int st,int en,int l,int r,int val)
{
	if (en<l || st>r || r<l)
	return 0;
	if (l<=st && en<=r)
	{
		if (val)
		{
			tree[node]=1;
			h[node]=pw[st];
		}
		return 1;
	}
	int mid=(st+en)/2;
	lc[node]=++cn;
	if (!update(lc[node],lc[node2],st,mid,l,r,val))
	{
		cn--;
		lc[node]=lc[node2];
	}
	rc[node]=++cn;
	if (!update(rc[node],rc[node2],mid+1,en,l,r,val))
	{
		cn--;
		rc[node]=rc[node2];
	}
	tree[node]=tree[lc[node]]+tree[rc[node]];
	h[node]=(h[lc[node]]+h[rc[node]])%mod;
	return 1;
}
int find(int node,int st,int en,int l)
{
	push(node,st,en);
	if (en<l || tree[node]==en-st+1)
	return -1;
	if (st==en)
	return st;
	int mid=(st+en)/2,tmp=find(lc[node],st,mid,l);
	if (tmp==-1)
	tmp=find(rc[node],mid+1,en,l);
	return tmp;
}
bool cmp(int node,int node2,int st,int en)
{
	push(node,st,en);
	push(node2,st,en);
	if (st==en)
	return (tree[node]<tree[node2]);
	int mid=(st+en)/2;
	if (h[rc[node]]==h[rc[node2]])
	return cmp(lc[node],lc[node2],st,mid);
	return cmp(rc[node],rc[node2],mid+1,en);
}
struct cmps
{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b) const
	{
		if (cmp(a.first,b.first,0,MX))
		return 1;
		if (cmp(b.first,a.first,0,MX))
		return 0;
		return (a.second<b.second);
	}
};
int main()
{
	int n,m,ss,tt;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	scanf("%d%d",&ss,&tt);
	pw[0]=1;
	for (int i=1;i<=MX;i++)
	pw[i]=(2*pw[i-1])%mod;
	set<pair<int,int>,cmps> s;
	dist[ss]=++cn;
	s.insert({1,ss});
	while (!s.empty())
	{
		auto p=*s.begin();
		s.erase(s.begin());
		for (auto u:v[p.second])
		{
			int nroot=++cn,pos=find(p.first,0,MX,u.second);
			update(nroot,p.first,0,MX,pos,pos,1);
			if (pos>u.second)
			{
				int tmp=nroot;
				nroot=++cn;
				update(nroot,tmp,0,MX,u.second,pos-1,0);
			}
			if (!dist[u.first] || cmp(nroot,dist[u.first],0,MX))
			{
				s.erase({dist[u.first],u.first});
				dist[u.first]=nroot;
				s.insert({dist[u.first],u.first});
				par[u.first]=p.second;
			}
		}
	}
	if (!dist[tt])
	printf("-1");
	else
	{
		printf("%d\n",h[dist[tt]]);
		stack<int> ans;
		while (tt!=ss)
		{
			ans.push(tt);
			tt=par[tt];
		}
		ans.push(tt);
		printf("%d\n",ans.size());
		while (!ans.empty())
		{
			printf("%d ",ans.top());
			ans.pop();
		}
	}
}