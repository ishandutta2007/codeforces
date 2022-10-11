#include <bits/stdc++.h>
using namespace std;
bool vis[500005];
set<int,greater<int> > o[500005];
set<pair<int,int> > s;
vector<int> v[500005],p;
void add(int node)
{
	s.erase({*o[node].begin(),node});
	vis[node]=1;
	p.push_back(node);
	for (int u:v[node])
	{
		if (!vis[u])
		{
			s.erase({*o[u].begin(),u});
			o[u].insert(p.size());
			s.insert({*o[u].begin(),u});
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		s.clear();
		for (int i=1;i<=n;i++)
		{
			v[i].clear();
			o[i].clear();
			o[i].insert(0);
			s.insert({0,i});
			vis[i]=0;
		}
		p.clear();
		while (m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		vector<pair<int,int> > ans;
		for (int i=1;i<=n;i++)
		{
			if (!vis[i])
			{
				add(i);
				while (!p.empty())
				{
					while (!v[p.back()].empty())
					{
						int tmp=v[p.back()].back();
						v[p.back()].pop_back();
						if (!vis[tmp])
						add(tmp);
					}
					if (s.empty())
					break;
					ans.push_back({p.back(),s.begin()->second});
					p.pop_back();
					vis[s.begin()->second]=1;
					s.erase(s.begin());
				}
			}
		}
		if (p.size()>(n-1)/2)
		{
			printf("PATH\n%d\n",p.size());
			for (int i:p)
			printf("%d ",i);
			printf("\n");
		}
		else
		{
			printf("PAIRING\n%d\n",ans.size());
			for (auto i:ans)
			printf("%d %d\n",i.first,i.second);
		}
	}
}