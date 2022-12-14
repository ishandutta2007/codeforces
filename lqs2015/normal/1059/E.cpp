#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<cassert>
using namespace std;
long long sum[111111],n,S,L,x,dp[111111],deep[111111],tree[444444],lazy[444444],dep[111111],w[111111],sz,cnt,beg[111111],en[111111];
vector<long long> g[111111];
set<pair<long long,long long> > s,ss;
void pushdown(long long node)
{
	if (lazy[node])
	{
		tree[node*2]+=lazy[node];tree[node*2+1]+=lazy[node];
		lazy[node*2]+=lazy[node];lazy[node*2+1]+=lazy[node];
		lazy[node]=0;
	}
}
void update(long long beg,long long en,long long l,long long r,long long node,long long x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		tree[node]+=x;
		lazy[node]+=x;
		return;
	}
	pushdown(node);
	long long mid=(l+r)/2;
	update(beg,en,l,mid,node*2,x);
	update(beg,en,mid+1,r,node*2+1,x);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
long long query(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return 1e11;
	if (l>=beg && r<=en) return tree[node];
	pushdown(node);
	long long mid=(l+r)/2;
	return min(query(beg,en,l,mid,node*2),query(beg,en,mid+1,r,node*2+1));
}
void dfs(long long i,long long fa)
{
	dep[i]=dep[fa]+w[i];
	deep[i]=deep[fa]+1;
	beg[i]=++cnt;
	long long cur=0;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		dfs(to,i);
		cur+=dp[to];
	}
	sum[i]=cur;
	en[i]=cnt;
	s.insert(make_pair(-dep[i],beg[i])); 
	while(!s.empty())
	{
		long long x=s.begin()->first;
		if (-x-dep[fa]>S) 
		{
			update(s.begin()->second,s.begin()->second,1,sz,1,1e11);
			s.erase(s.begin()); 
		}
		else break;
	}
	ss.insert(make_pair(-deep[i],beg[i])); 
	while(!ss.empty())
	{
		long long x=ss.begin()->first;
		if (-x-deep[i]>=L) 
		{
			update(ss.begin()->second,ss.begin()->second,1,sz,1,1e11);
			ss.erase(ss.begin()); 
		}
		else break;
	}
	dp[i]=query(beg[i],en[i],1,sz,1)+sum[i]+1;
	if (dp[i]>=1e10)
	{
		printf("-1\n");
		exit(0);
	}
	update(beg[i],en[i],1,sz,1,sum[i]-dp[i]);
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&L,&S);
	for (long long i=1;i<=n;i++) scanf("%I64d",&w[i]);
	for (long long i=2;i<=n;i++)
	{
		scanf("%I64d",&x);
		g[x].push_back(i); 
	}
	sz=1;
	while(sz<n) sz*=2;
	dfs(1,0);
	if (dp[1]>1e11) printf("-1\n");
	else printf("%I64d\n",dp[1]);
	return 0;
}