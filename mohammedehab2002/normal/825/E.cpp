#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> v[100005],rev[100005];
int deg[100005],ans[100005];
bool used[100005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		rev[b].push_back(a);
		deg[a]++;
	}
	set<pair<int,int> > s;
	for (int i=1;i<=n;i++)
	s.insert({deg[i],n-i});
	for (int i=n;i>=1;i--)
	{
		auto p=*s.begin();
		s.erase(s.begin());
		p.second=n-p.second;
		ans[p.second]=i;
		used[p.second]=1;
		for (int u:rev[p.second])
		{
			if (!used[u])
			{
				s.erase({deg[u],n-u});
				deg[u]--;
				s.insert({deg[u],n-u});
			}
		}
	}
	for (int i=1;i<=n;i++)
	printf("%d ",ans[i]);
}