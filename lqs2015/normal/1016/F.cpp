#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
long long n,m,x,y,z,node[333333],cnt,sum[333333],a[333333],mx,tree[2222222],sz,cur,ct;
vector<pair<long long,long long> > g[333333];
bool isit[333333],f;
stack<long long> st;
bool dfs(long long i,long long fa)
{
	if (i==n)
	{
		st.push(i);
		return 1; 
	}
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first;
		if (to==fa) continue;
		if (dfs(to,i))
		{
			st.push(i);
			return 1; 
		}
	}
	return 0;
}
void rfs(long long i,long long fa,long long sum)
{
	mx=max(mx,sum);
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==fa || val==-1e18) continue;
		rfs(to,i,sum+val);
	}
}
void build(long long l,long long r,long long node)
{
	if (l==r)
	{
		if (l<=cnt) tree[node]=a[l]-sum[l];
		else tree[node]=-1e18;
		return;
	}
	long long mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}
long long query(long long beg,long long en,long long l,long long r,long long node)
{
	if (l>en || r<beg) return -1e18;
	if (l>=beg && r<=en) return tree[node];
	long long mid=(l+r)/2;
	return max(query(beg,en,l,mid,node*2),query(beg,en,mid+1,r,node*2+1));
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));  
	}
	dfs(1,0);
	while(!st.empty())
	{
		cnt++;
		x=st.top();
		st.pop();
		node[cnt]=x;
		isit[x]=1;
		if (cnt!=1)
		{
			for (long long i=0;i<g[x].size();i++)
			{
				if (g[x][i].first==node[cnt-1]) sum[cnt]=sum[cnt-1]+g[x][i].second;
			}
			for (long long i=0;i<g[x].size();i++)
			{
				if (g[x][i].first==node[cnt-1]) g[x][i].second=-1e18;
			}
			for (long long i=0;i<g[node[cnt-1]].size();i++)
			{
				if (g[node[cnt-1]][i].first==x) g[node[cnt-1]][i].second=-1e18;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		ct=0;
		for (int j=0;j<g[i].size();j++)
		{
			if (!isit[g[i][j].first]) ct++;
		}
		if (ct>=2) f=1;
	}
	if (f)
	{
		for (long long i=1;i<=m;i++)
		{
			scanf("%I64d",&x);
			printf("%I64d\n",sum[cnt]);
		}
		return 0;
	}
	for (long long i=1;i<=cnt;i++)
	{
		mx=0;
		rfs(node[i],0,0);
		a[i]=mx;
	}
	sz=1;
	while(sz<cnt) sz*=2;
	build(1,sz,1);
	mx=-1e18;
	for (long long i=1;i<=cnt;i++)
	{
		cur=query(i+2,cnt,1,sz,1)+sum[i]+a[i];
		mx=max(mx,cur);
		if (!a[i+1] && !a[i]) continue;
		cur=query(i+1,cnt,1,sz,1)+sum[i]+a[i];
		mx=max(mx,cur);
	}
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d",&x);
		if (mx+x>=0) printf("%I64d\n",sum[cnt]);
		else printf("%I64d\n",sum[cnt]+mx+x); 
	}
	return 0;
}