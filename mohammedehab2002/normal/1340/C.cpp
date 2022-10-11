#include <bits/stdc++.h>
using namespace std;
int n,m,g,r,a[10005],dist[11111111];
int cn(int i,int j)
{
	return i*(g+1)+j;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	scanf("%d",&a[i]);
	sort(a,a+m);
	scanf("%d%d",&g,&r);
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<=g;j++)
		dist[cn(i,j)]=1e9;
	}
	deque<pair<int,int> > s;
	s.push_back({0,0});
	dist[0]=0;
	int ans=1e9;
	vector<pair<int,int> > v;
	while (!s.empty())
	{
		auto node=s.front();
		s.pop_front();
		int i=node.second/(g+1),j=node.second%(g+1);
		if (i==m-1)
		ans=min(ans,node.first*(g+r)+j);
		if (dist[node.second]<node.first)
		continue;
		v.clear();
		if (i && j+a[i]-a[i-1]<=g)
		v.push_back({cn(i-1,j+a[i]-a[i-1]),0});
		if (i!=m-1 && j+a[i+1]-a[i]<=g)
		v.push_back({cn(i+1,j+a[i+1]-a[i]),0});
		if (j==g)
		v.push_back({cn(i,0),1});
		for (auto u:v)
		{
			if (node.first+u.second<dist[u.first])
			{
				dist[u.first]=node.first+u.second;
				if (u.second)
				s.push_back({dist[u.first],u.first});
				else
				s.push_front({dist[u.first],u.first});
			}
		}
	}
	if (ans==1e9)
	ans=-1;
	printf("%d",ans);
}