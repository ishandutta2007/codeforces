#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,pa[222222],ans,pre,pos;
pair<int,pair<int,int> > ed[222222]; 
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		ed[i]=make_pair(z,make_pair(x,y));
	}
	sort(ed+1,ed+m+1);
	for (int i=1;i<=n;i++)
	{
		pa[i]=i;
	}
	pre=pos=1;
	while(pos<=m)
	{
		pre=pos;
		while(pos<=m && ed[pos].first==ed[pre].first) pos++;
		for (int i=pre;i<pos;i++)
		{
			int rx=root(ed[i].second.first),ry=root(ed[i].second.second);
			if (rx!=ry) ans++;
		}
		for (int i=pre;i<pos;i++)
		{
			int rx=root(ed[i].second.first),ry=root(ed[i].second.second);
			if (rx!=ry)
			{
				ans--;
				pa[rx]=ry;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}