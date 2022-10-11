#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<pair<int,int> > v[200005];
pair<int,int> arr[200005];
int deg[200005],ans[200005];
set<pair<int,int> > s;
void upd(int u)
{
	if (s.find({deg[u],u})!=s.end())
	{
		s.erase({deg[u],u});
		deg[u]--;
		s.insert({deg[u],u});
	}
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&arr[i].first,&arr[i].second);
		deg[arr[i].first]++;
		deg[arr[i].second]++;
		v[arr[i].first].push_back({arr[i].second,i});
		v[arr[i].second].push_back({arr[i].first,i});
	}
	for (int i=1;i<=n;i++)
	s.insert({deg[i],i});
	for (int i=m-1;i>=0;i--)
	{
		while (!s.empty())
		{
			auto p=*s.begin();
			if (p.first>=k)
			break;
			s.erase(s.begin());
			for (auto u:v[p.second])
			{
				if (u.second<=i)
				upd(u.first);
			}
		}
		ans[i]=s.size();
		if (s.find({deg[arr[i].second],arr[i].second})!=s.end())
		upd(arr[i].first);
		if (s.find({deg[arr[i].first],arr[i].first})!=s.end())
		upd(arr[i].second);
	}
	for (int i=0;i<m;i++)
	printf("%d\n",ans[i]);
}