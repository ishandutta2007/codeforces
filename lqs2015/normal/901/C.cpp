#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long mn[333333],cnt,n,m,x,y,dfn[333333],used[333333],pa[333333],mnn,mx,cur,far[333333],q,sz,bit[666666],l,r,L,R,mid;
void update(long long p,long long x)
{
	while(p<=sz)
	{
		bit[p]+=x;
		p+=p&(-p);
	}
}
long long get(long long p)
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
vector<long long> g[333333];
void dfs(long long i,long long fa)
{
	used[i]=1;pa[i]=fa;dfn[i]=++cnt;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		if (!used[to]) dfs(to,i);
		else if (dfn[to]<dfn[i])
		{
			mnn=i;mx=i;cur=i;
			while(cur!=to)
			{
				cur=pa[cur];
				mnn=min(mnn,cur);
				mx=max(mx,cur);
			}
			mn[mnn]=min(mn[mnn],mx);
		}
	}
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (long long i=1;i<=n;i++) mn[i]=1e9;
	for (long long i=1;i<=n;i++)
	{
		if (!used[i]) dfs(i,0);
	}
	far[n+1]=1e9;
	for (long long i=n;i>=1;i--)
	{
		far[i]=min(far[i+1],mn[i]-1);
	}
	sz=1;
	while(sz<n) sz*=2;
	scanf("%I64d",&q);
	for (long long i=1;i<=n;i++) update(i,far[i]-i+1);
	while(q--)
	{
		scanf("%I64d%I64d",&l,&r);
		L=l;R=r;
		while(L<=R)
		{
			mid=(L+R)>>1;
			if (far[mid]>r) R=mid-1;
			else L=mid+1;
		}
		printf("%I64d\n",(r-R)*r-(R+r-1)*(r-R)/2+get(R)-get(l-1));
	}
	return 0;
}