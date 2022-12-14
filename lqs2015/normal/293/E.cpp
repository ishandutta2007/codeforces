#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
long long n,l,w,x,y,z,ans,sub[111111],bit[444444],psz;
vector<pair<long long,long long> > g[111111];
bool conc[111111];
multiset<long long> s;
void calsub(long long i,long long fa)
{
	sub[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first;
		if (conc[to] || to==fa) continue;
		calsub(to,i);
		sub[i]+=sub[to];
	}
}
pair<long long,long long> findgrav(long long i,long long fa,long long all)
{
	pair<long long,long long> res=make_pair(1e9,1e9);
	long long mx=0,sum=0;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first;
		if (conc[to] || to==fa) continue;
		res=min(res,findgrav(to,i,all));
		mx=max(mx,sub[to]);
		sum+=sub[to];
	}
	mx=max(mx,all-sum);
	res=min(res,make_pair(mx,i));
	return res;
}
void dfs(long long i,long long fa,long long sum,long long len,vector<pair<long long,long long> > &ll)
{
	ll.push_back(make_pair(sum,len)); 
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==fa || conc[to]) continue;
		dfs(to,i,sum+val,len+1,ll); 
	}
}
void update(long long p,long long f)
{
	while(p<=psz)
	{
		bit[p]+=f;
		p+=p&(-p);
	}
}
long long query(long long p)
{
	long long res=0;
	while(p>0)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
long long pairit(vector<pair<long long,long long> > &v)
{
	sort(v.begin(),v.end());
	long long j=v.size()-1,res=0;
	for (long long i=0;i<v.size();i++) 
	{
		update(v[i].second+1,1);
	}
	for (long long i=0;i<v.size();i++)
	{
		while(j>=0 && v[j].first+v[i].first>w) 
		{
			update(v[j].second+1,-1); 
			j--;
		}
		res+=query(l-v[i].second+1);
		if (v[i].second+v[i].second<=l && v[i].first+v[i].first<=w) res--;
	}
	for (long long i=j;i>=0;i--)
	{
		update(v[i].second+1,-1);
	}
	return res/2;
}
void gravity(long long i)
{
	calsub(i,0);
	long long pos=findgrav(i,0,sub[i]).second;
	conc[pos]=1;
	for (long long j=0;j<g[pos].size();j++)
	{
		long long to=g[pos][j].first;
		if (!conc[to]) gravity(to);
	}
	vector<pair<long long,long long> > ll,tot;
	ll.clear();tot.clear();
	tot.push_back(make_pair(0,0)); 
	for (long long j=0;j<g[pos].size();j++)
	{
		long long to=g[pos][j].first,val=g[pos][j].second;
		if (conc[to]) continue;
		ll.clear();
		dfs(to,pos,val,1,ll);
		ans-=pairit(ll);
		for (long long k=0;k<ll.size();k++) tot.push_back(ll[k]); 
	}
	ans+=pairit(tot);
	conc[pos]=0;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&l,&w);
	psz=1;
	while(psz<=n) psz*=2;
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[i+1].push_back(make_pair(x,y));
		g[x].push_back(make_pair(i+1,y));
	}
	gravity(1);
	printf("%I64d\n",ans);
	return 0;
}