#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
long long n,m,k,cntu,co[111111],cost,precost,res;
long long d[111111],f[111111],t[111111],c[111111],cnth,cntq;
pair<long long,long long> hq[111111],jl[111111];
set<pair<long long,long long> > s;
bool used[111111],fl;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d%I64d",&d[i],&f[i],&t[i],&c[i]);
		if (!f[i]) hq[++cnth]=make_pair(d[i],i);
		else jl[++cntq]=make_pair(d[i],i);
	}
	sort(hq+1,hq+cnth+1);
	sort(jl+1,jl+cntq+1);
	reverse(hq+1,hq+cnth+1);
	precost=1e18;res=1e18;
	for (int i=1;i<=cnth;i++)
	{
		if (!used[t[hq[i].second]])
		{
			cntu++;
			used[t[hq[i].second]]=1;
			co[t[hq[i].second]]=c[hq[i].second];
			cost+=c[hq[i].second];
		}
		if (c[hq[i].second]<co[t[hq[i].second]])
		{
			cost=cost-co[t[hq[i].second]]+c[hq[i].second];
			co[t[hq[i].second]]=c[hq[i].second];
		}
		if (cntu==n) fl=1; 
		if (fl)
		{
			if (cost<precost) 
			{
				s.insert(make_pair(d[hq[i].second],cost));
				precost=cost;
			}
		}
	}
	if (!fl)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=n;i++) co[i]=0;
	cost=0;fl=0;cntu=0;precost=1e18;
	for (int i=1;i<=n;i++) used[i]=0;
	for (int i=1;i<=cntq;i++)
	{
		if (!used[f[jl[i].second]])
		{
			used[f[jl[i].second]]=1;
			cntu++;
			co[f[jl[i].second]]=c[jl[i].second];
			cost+=c[jl[i].second];
		}
		if (c[jl[i].second]<co[f[jl[i].second]])
		{
			cost=cost-co[f[jl[i].second]]+c[jl[i].second];
			co[f[jl[i].second]]=c[jl[i].second];
		}
		if (cntu==n) fl=1;
		if (fl)
		{
			if (cost>=precost) continue;
			set<pair<long long,long long> >::iterator it=s.lower_bound(make_pair(d[jl[i].second]+k+1,0));
			if (it==s.end()) continue;
			res=min(res,it->second+cost);
			precost=cost;
		}
	}
	if (res==1e18) 
	{
		printf("-1\n");
		return 0;
	}
	printf("%I64d\n",res);
	return 0;
}