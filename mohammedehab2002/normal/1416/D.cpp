#include <bits/stdc++.h>
using namespace std;
bool del[300005];
int perm[200005],a[300005],b[300005],par[200005],sz[200005];
struct query
{
	int t,i,tpar,tsz,ts,ans;
	query(int t,int i):t(t),i(i){}
};
struct cmp
{
	bool operator()(const int &x,const int &y) const
	{
		if (perm[x]==perm[y])
		return (x<y);
		return (perm[x]>perm[y]);
	};
};
set<int,cmp> s[200005];
vector<pair<int,int> > upar,usz;
vector<pair<pair<int,int>,vector<int> > > us;
vector<query> v;
int find(int x)
{
	if (!par[x])
	return x;
	return find(par[x]);
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	return;
	if (sz[x]>sz[y])
	swap(x,y);
	upar.push_back({x,par[x]});
	par[x]=y;
	usz.push_back({y,sz[y]});
	sz[y]+=sz[x];
	us.push_back({{x,y},vector<int>()});
	for (int i:s[x])
	{
		s[y].insert(i);
		us[(int)us.size()-1].second.push_back(i);
	}
	s[x].clear();
}
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&perm[i]);
		s[i].insert(i);
		sz[i]=1;
	}
	for (int i=1;i<=m;i++)
	scanf("%d%d",&a[i],&b[i]);
	for (int _=0;_<q;_++)
	{
		int t,i;
		scanf("%d%d",&t,&i);
		v.push_back(query(t,i));
		if (t==2)
		del[i]=1;
	}
	for (int i=1;i<=m;i++)
	{
		if (!del[i])
		v.push_back(query(2,i));
	}
	reverse(v.begin(),v.end());
	for (auto &p:v)
	{
		if (p.t==2)
		{
			p.tpar=upar.size();
			p.tsz=usz.size();
			p.ts=us.size();
			Union(a[p.i],b[p.i]);
		}
	}
	reverse(v.begin(),v.end());
	for (auto p:v)
	{
		if (p.t==2)
		{
			while (upar.size()!=p.tpar)
			{
				par[upar.back().first]=upar.back().second;
				upar.pop_back();
			}
			while (usz.size()!=p.tsz)
			{
				sz[usz.back().first]=usz.back().second;
				usz.pop_back();
			}
			while (us.size()!=p.ts)
			{
				for (int i:us.back().second)
				{
					s[us.back().first.first].insert(i);
					s[us.back().first.second].erase(i);
				}
				us.pop_back();
			}
		}
		else
		{
			int r=find(p.i),mx=*s[r].begin();
			s[r].erase(s[r].begin());
			printf("%d\n",perm[mx]);
			perm[mx]=0;
			s[r].insert(mx);
		}
	}
}