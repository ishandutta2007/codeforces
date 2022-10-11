#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
stack<int> st;
vector<int> v[205];
map<pair<int,int>,int> vis,add;
void dfs(int node)
{
	while (!v[node].empty())
	{
		int u=v[node].back();
		v[node].pop_back();
		if (!vis[{u,node}])
		continue;
		vis[{u,node}]--;
		vis[{node,u}]--;
		dfs(u);
	}
	st.push(node);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		v[i].clear();
		add.clear();
		vis.clear();
		while (m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
			vis[{a,b}]++;
			vis[{b,a}]++;
		}
		int o=-1,ans=n;
		for (int i=1;i<=n;i++)
		{
			if (v[i].size()%2)
			{
				ans--;
				if (o==-1)
				o=i;
				else
				{
					v[i].push_back(o);
					v[o].push_back(i);
					vis[{i,o}]++;
					vis[{o,i}]++;
					add[{i,o}]++;
					add[{o,i}]++;
					o=-1;
				}
			}
		}
		printf("%d\n",ans);
		for (int i=1;i<=n;i++)
		{
			dfs(i);
			while (1)
			{
				int u=st.top();
				st.pop();
				if (st.empty())
				break;
				if (add[{u,st.top()}])
				{
					add[{u,st.top()}]--;
					add[{st.top(),u}]--;
					continue;
				}
				printf("%d %d\n",u,st.top());
			}
		}
	}
}