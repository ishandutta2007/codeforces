#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
int A[3<<17];
int cp[3<<17];
vector<int>col[3<<17];
vector<int>G[3<<17];
int dep[3<<17],pr[20][3<<17];
void dfs(int u,int p,int d)
{
	dep[u]=d;
	pr[0][u]=p;
	for(int v:G[u])if(v!=p)dfs(v,u,d+1);
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	for(int k=0;k<20;k++)if(dep[v]-dep[u]>>k&1)v=pr[k][v];
	if(u==v)return u;
	for(int k=20;k--;)if(pr[k][u]!=pr[k][v])
	{
		u=pr[k][u];
		v=pr[k][v];
	}
	return pr[0][u];
}
const long long mod=998244353;
using Tp=pair<pair<int,long long>,long long>;
Tp dfs2(int u,int p)
{
	Tp ans;
	if(A[u]>=0)
	{
		long long ret=1;
		for(int v:G[u])if(v!=p)
		{
			Tp q=dfs2(v,u);
			long long mul=0;
			if(q.first.first==-1)mul=q.second;
			else
			{
				if(q.first.first==A[u])mul=q.first.second;
				else
				{
					mul=q.second;
					if(dep[cp[q.first.first]]>dep[u])mul=(mul+q.first.second)%mod;
					else mul=0;
				}
			}
			ret=ret*mul%mod;
		}
		ans.first=make_pair(A[u],ret);
		ans.second=0;
	}
	else
	{
		vector<Tp>X,Y;
		long long ret=1;
		for(int v:G[u])if(v!=p)
		{
			Tp q=dfs2(v,u);
			if(q.first.first==-1)
			{
				ret=ret*q.second%mod;
			}
			else if(dep[cp[q.first.first]]>dep[u])X.push_back(q);
			else Y.push_back(q);
		}
		if(Y.empty())
		{
			int n=X.size();
			vector<long long>L(n+1),R(n+1);
			L[0]=R[n]=1;
			for(int i=0;i<n;i++)L[i+1]=(X[i].first.second+X[i].second)%mod*L[i]%mod;
			for(int i=n;i--;)R[i]=(X[i].first.second+X[i].second)%mod*R[i+1]%mod;
			long long sec=ret*L[n]%mod;
			long long fst=0;
			int color=-1;
			for(int i=0;i<n;i++)
			{
				fst+=L[i]*R[i+1]%mod*X[i].first.second%mod;
				fst%=mod;
				color=X[i].first.first;
			}
			ans.first=make_pair(color,fst);
			ans.second=sec;
		}
		else
		{
			int color=Y[0].first.first;
			for(int i=0;i<Y.size();i++)
			{
				if(Y[i].first.first!=color)
				{
					return make_pair(make_pair(-1,0),0);
				}
				ret=ret*Y[i].first.second%mod;
			}
			for(Tp q:X)ret=(q.first.second+q.second)%mod*ret%mod;
			ans.first=make_pair(color,ret);
			ans.second=0;
		}
	}
	//printf("%d %d %lld %lld\n",u,ans.first.first,ans.first.second,ans.second);
	return ans;
}
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		if(A[i]>=0)col[A[i]].push_back(i);
	}
	for(int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1,0);
	for(int k=1;k<20;k++)for(int i=0;i<N;i++)
	{
		if(pr[k-1][i]==-1)pr[k][i]=-1;
		else pr[k][i]=pr[k-1][pr[k-1][i]];
	}
	for(int i=0;i<K;i++)
	{
		cp[i]=col[i][0];
		for(int j=1;j<col[i].size();j++)cp[i]=lca(cp[i],col[i][j]);
		//printf("%d %d %d\n",i,cp[i],dep[cp[i]]);
	}
	printf("%d\n",(int)dfs2(0,-1).first.second);
}