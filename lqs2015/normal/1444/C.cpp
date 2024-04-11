#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[555555],pa[555555],val[555555],x[555555],y[555555],num,pre,pos,nm,sz[555555];
bool can[555555],flg;
long long ans;
vector<pair<int,int> > v1,v2,v3;
vector<pair<int,int> > g[555555];
pair<int,int> cur;
int root(int x)
{
	if (pa[x]==x) return x;
	int rt=root(pa[x]);
	v1.push_back(make_pair(x,pa[x]));
	if (val[pa[x]])
	{
		v2.push_back(make_pair(x,val[x]));
		val[x]^=val[pa[x]];
	}
	pa[x]=rt;
	return rt;
}
bool Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry)
	{
		if (val[x]==val[y]) return 0;
		return 1;
 	}
 	if (sz[rx]<sz[ry])
 	{
	 	v2.push_back(make_pair(rx,val[rx]));
	 	val[rx]=val[x]^val[y]^1;
	 	v1.push_back(make_pair(rx,pa[rx]));
	 	pa[rx]=ry;
	 	v3.push_back(make_pair(ry,sz[ry]));
	 	sz[ry]+=sz[rx];
	}
 	else
 	{
 		v2.push_back(make_pair(ry,val[ry]));
	 	val[ry]=val[x]^val[y]^1;
	 	v1.push_back(make_pair(ry,pa[ry]));
	 	pa[ry]=rx;
	 	v3.push_back(make_pair(rx,sz[rx]));
	 	sz[rx]+=sz[ry];
	}
 	return 1;
}
void undo()
{
	while(!v1.empty())
	{
		cur=v1.back();
		v1.pop_back();
		pa[cur.first]=cur.second;
	}
	while(!v2.empty())
	{
		cur=v2.back();
		v2.pop_back();
		val[cur.first]=cur.second;
	}
	while(!v3.empty())
	{
		cur=v3.back();
		v3.pop_back();
		sz[cur.first]=cur.second;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) sz[i]=1;
	for (int i=1;i<=n;i++) pa[i]=i;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (c[x[i]]>c[y[i]]) swap(x[i],y[i]);
		if (c[x[i]]==c[y[i]])
		{
			if (!Union(x[i],y[i])) can[c[x[i]]]=1;
		}
		else
		{
			g[c[x[i]]].push_back(make_pair(c[y[i]],i));
		}
	}
	for (int i=1;i<=k;i++)
	{
		if (!can[i])
		{
			sort(g[i].begin(),g[i].end());
			num++;
		}
	}
	v1.clear();v2.clear();v3.clear();
	for (int i=1;i<=k;i++)
	{
		if (can[i]) continue;
		num--;
		pre=pos=0;nm=num;
		while(pos<g[i].size())
		{
			pre=pos;
			while(pos<g[i].size() && g[i][pos].first==g[i][pre].first) pos++;
			if (can[g[i][pre].first]) continue;
			flg=0;nm--;
			for (int j=pre;j<pos;j++)
			{
				int id=g[i][j].second;
				if (!Union(x[id],y[id])) flg=1;
			}
			if (!flg) ans++;
			undo();
		}
		ans+=nm;
	}
	printf("%lld\n",ans);
	return 0;
}