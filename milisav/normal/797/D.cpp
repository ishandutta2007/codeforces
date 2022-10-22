#include <bits\stdc++.h>
using namespace std;
int n;
int v[200000];
int l[200000];
int r[200000];
int t;
int p[200000];
bool d[200000];
int c[200000];
map<int,int> m;
int s;
vector<pair<int,pair<int,int> > > q;
void dfs()
{
	q.push_back(make_pair(t,make_pair(-1,1000000007)));
	int ind=0;
	int u;
	while(ind<q.size())
	{
		u=q[ind].first;
		if(v[u]<q[ind].second.second && v[u]>q[ind].second.first) d[u]=true;
		if(l[u]!=-1)
		{
			q.push_back(make_pair(l[u],make_pair(q[ind].second.first,min(q[ind].second.second,v[u]))));
		}
		if(r[u]!=-1)
		{
			q.push_back(make_pair(r[u],make_pair(max(q[ind].second.first,v[u]),q[ind].second.second)));
		}
		ind++;
	}
}
int main()
{
	int u;	
	scanf("%d",&n);
	for(int i=0;i<n;i++) p[i]=i;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&v[i],&l[i],&r[i]);
		if(l[i]!=-1)
		{
			l[i]--;
			c[i]++;
			p[l[i]]=i;
		}
		if(r[i]!=-1)
		{
			r[i]--;
			c[i]++;
			p[r[i]]=i;
		}
		//if(l[i]==-1 && r[i]==-1) q.push_back(i);
	}
	for(int i=0;i<n;i++) if(p[i]==i) t=i;
	dfs();
	for(int i=0;i<n;i++)
	{
		if(!d[i]) m[v[i]]++;
		else m[v[i]]=-1000000;
	}
	sort(v,v+n);
	s=0;
	if(m[v[0]]>0) s+=m[v[0]];
	for(int i=1;i<n;i++) if(v[i]!=v[i-1] && m[v[i]]>0) s+=m[v[i]];
	printf("%d",s);
	return 0;
}