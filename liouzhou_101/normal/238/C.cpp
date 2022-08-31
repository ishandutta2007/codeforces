#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int MaxN=3010;

int n;
vector<pair<int,int> > v[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(y,0));
		v[y].push_back(make_pair(x,1));
	}
}

int F[MaxN],G[MaxN],pF[MaxN],pG[MaxN],get[MaxN],d[MaxN];

void solve(int x,int p)
{
	d[x]=min(d[x],F[x]-G[x]);
	pF[x]=pG[x]=0;
	for (vector<pair<int,int> >::iterator it=v[x].begin();it!=v[x].end();++it)
	{
		if (it->first==p) continue;
		if (it->second==0)
		{
			F[it->first]=F[x];
			G[it->first]=G[x]+1;
			++pG[x];
		}
		else
		{
			F[it->first]=F[x]+1;
			G[it->first]=G[x];
			++pF[x];
		}
		d[it->first]=d[x];
		solve(it->first,x);
		pF[x]+=pF[it->first];
		pG[x]+=pG[it->first];
	}
	get[x]=G[x]+d[x];
}

void work()
{
	int ans=MaxN;
	for (int i=1;i<=n;++i)
	{
		d[i]=F[i]=G[i]=0;
		solve(i,0);
		ans=min(ans,pF[i]);
		for (int j=1;j<=n;++j) if (i!=j)
			ans=min(ans,get[j]+pF[i]-F[j]);
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}