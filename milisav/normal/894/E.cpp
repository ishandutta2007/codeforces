#include <bits/stdc++.h>
using namespace std;
long long int n,m;
vector<pair<long long int,long long int> > a[2000000];
stack<long long int> sr;
bool is[1000005];
long long int sl[30005];
long long int s;
long long int sur[30005];
long long int co[1000005];
long long int disc[1000005];
long long int low[10000005];
long long int ch[1000005];
vector<long long int> p[1000005];
vector<pair<long long int,long long int> > b[1000005];
long long int t=1;
long long int cr=1;
long long int c[1000005];
long long int sol[1000005];
void tarjan(long long int u)
{
	sr.push(u);
	//cout<<u<<endl;
	is[u]=true;
	disc[u]=t;
	low[u]=t;
	t++;
	long long int v;
	for(long long int i=0;i<a[u].size();i++)
	{
		v=a[u][i].first;
		//cout<<u<<" "<<v<<" "<<disc[u]<<" "<<disc[v]<<" "<<low[u]<<" "<<low[v]<<endl;
		if(disc[v]==0)
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
		{
			if(is[v]) low[u]=min(low[u],disc[v]);
		}
	}
	if(low[u]==disc[u])
	{
		//cout<<sr.size()<<endl;
		while(sr.top()!=u)
		{
			v=sr.top();
			//cout<<v<<endl;
			is[v]=false;
			co[v]=cr;
			sr.pop();
		}
		v=sr.top();
		is[v]=false;
		co[v]=cr;
		sr.pop();
		cr++;
	}
}
long long int solu(long long int w)
{
	long long int l=0;
	long long int r=20000;
	long long int mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(sur[mid]>=w) r=mid-1;
		else l=mid;
	}
	while(sur[l+1]<w) l++;
	l++;
	while(sur[l-1]>w) l--;
	long long int u,v,q;
	v=w;
	u=l;
	q=sl[l-1];
	//cout<<l<<endl;
	//cout<<l<<" "<<sl[l]<<endl;
	return v*u-q;
}
long long int best_path(long long int u)
{
	vector<long long int> q;
	for(long long int i=1;i<cr;i++) if(ch[i]==0) q.push_back(i);
	long long int ind=0;
	long long int v;
	//cout<<co[0]<<" "<<co[1]<<" "<<co[2]<<endl;
	while(ind<q.size())
	{
		v=q[ind];
		sol[v]=c[v];
		//cout<<v<<endl;
		for(long long int i=0;i<b[v].size();i++)
		{
			//cout<<b[v][i].second<<" "<<b[v][i].first<<" "<<c[v]<<endl;
			sol[v]=max(sol[v],b[v][i].second+sol[b[v][i].first]+c[v]);
		}
		for(long long int i=0;i<p[v].size();i++)
		{
			ch[p[v][i]]--;
			//cout<<sol[v]<<endl;
			if(ch[p[v][i]]==0) q.push_back(p[v][i]);
		}
		ind++;
	}
	return sol[u];
}
int main()
{
	sl[1]=1;
	sur[1]=1;
	for(long long int i=2;i<=20000;i++) 
	{
		sur[i]=(i*(i+1))/2;
		sl[i]=sl[i-1]+sur[i];
	}
	//cout<<solu(9)<<endl;
	long long int u,v,w;
	scanf("%lld %lld",&n,&m);
	for(long long int i=0;i<m;i++)
	{
		scanf("%lld %lld %lld",&u,&v,&w);
		u--;
		v--;
		a[u].push_back(make_pair(v,w));
	}
	scanf("%lld",&s);
	s--;
	tarjan(s);
	/*for(int i=0;i<100;i++)
	{
		cout<<solu(i)<<endl;
	}*/
	for(long long int i=0;i<n;i++)
	{
		if(co[i]>0)
		{
			for(long long int j=0;j<a[i].size();j++)
			{
				v=a[i][j].first;
				w=a[i][j].second;
				if(co[v]==co[i]) c[co[i]]+=solu(w);
				else
				{
					b[co[i]].push_back(make_pair(co[v],w));
					ch[co[i]]++;
					p[co[v]].push_back(co[i]);
				}
			}
		}
	}
	cout<<best_path(co[s])<<endl;
	return 0;
}