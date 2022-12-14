#include<bits/stdc++.h>
using namespace std;
int n,x[2222],y[2222],k[2222],c[2222],cnt;
pair<long long,pair<int,int> > ed[5555555];
long long ans;
int pa[2222],mn[2222];
vector<pair<int,int> > edge;
vector<int> v;
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	pa[rx]=ry;
	mn[ry]=min(mn[ry],mn[rx]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&k[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			ed[++cnt]=make_pair(1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),make_pair(i,j));
		}
	}
	sort(ed+1,ed+cnt+1);
	for (int i=1;i<=n;i++)
	{
		pa[i]=i;mn[i]=c[i];
		ans+=c[i];
	}
	for (int i=1;i<=cnt;i++)
	{
		int xx=ed[i].second.first,yy=ed[i].second.second;long long zz=ed[i].first;
		if (root(xx)==root(yy)) continue;
		if (max(mn[root(xx)],mn[root(yy)])>zz)
		{
			edge.push_back(make_pair(xx,yy));
			ans+=(zz-max(mn[root(xx)],mn[root(yy)]));
			Union(xx,yy);
		}
	}
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++)
	{
		if (root(i)==i) 
		{
			for (int j=1;j<=n;j++)
			{
				if (root(j)==i && c[j]==mn[i]) 
				{
					v.push_back(j);
					break;
				} 
			}
		}
	}
	printf("%d\n",(int)v.size());
	for (int i=0;i<v.size();i++) printf("%d ",v[i]);
	printf("\n");
	printf("%d\n",(int)edge.size());
	for (int i=0;i<edge.size();i++) printf("%d %d\n",edge[i].first,edge[i].second);
	return 0;
}