#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,k,x,y,z,ans,sub[111111];
vector<pair<long long,long long> > g[111111];
bool conc[111111];
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
void dfs(long long i,long long fa,long long sum,vector<long long> &l)
{
	l.push_back(sum); 
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to==fa || conc[to]) continue;
		dfs(to,i,sum+val,l); 
	}
}
long long pairit(vector<long long> &v,long long k)
{
	sort(v.begin(),v.end());
	long long j=v.size()-1,res=0;
	for (long long i=0;i<v.size();i++)
	{
		while(j>=0 && v[j]+v[i]>k) j--;
		if (j>i) res--;
		res+=(j+1);
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
	vector<long long> l,tot;
	l.clear();tot.clear();
	tot.push_back(0); 
	for (long long j=0;j<g[pos].size();j++)
	{
		long long to=g[pos][j].first,val=g[pos][j].second;
		if (conc[to]) continue;
		l.clear();
		dfs(to,pos,val,l);
		ans-=pairit(l,k);
		ans+=pairit(l,k-1);
		for (long long k=0;k<l.size();k++) tot.push_back(l[k]); 
	}
	ans+=pairit(tot,k);
	ans-=pairit(tot,k-1);
	conc[pos]=0;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (long long i=1;i<=n;i++) g[i].clear();
	ans=0;
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(make_pair(y,1));
		g[y].push_back(make_pair(x,1));
	}
	gravity(1);
	cout<<ans<<endl;
	return 0;
}