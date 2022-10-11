#include <bits/stdc++.h>
using namespace std;
vector<int> v1[300005],v2[300005];
int stt[300005],ent[300005],ct,ans;
struct cmp
{
	bool operator()(const int &a,const int &b) const
	{
		return (stt[a]<stt[b]);
	}
};
set<int,cmp> s;
void dfs1(int node)
{
	stt[node]=++ct;
	for (int u:v2[node])
	dfs1(u);
	ent[node]=ct;
}
void dfs2(int node)
{
	int er=0,ins=0;
	auto it=s.upper_bound(node);
	if (it!=s.begin() && ent[*prev(it)]>=ent[node])
	er=*prev(it);
	if (it==s.end() || ent[*it]>ent[node])
	ins=node;
	if (er)
	s.erase(er);
	if (ins)
	s.insert(ins);
	ans=max(ans,(int)s.size());
	for (int u:v1[node])
	dfs2(u);
	if (er)
	s.insert(er);
	if (ins)
	s.erase(ins);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			v1[i].clear();
			v2[i].clear();
		}
		for (int i=2;i<=n;i++)
		{
			int p;
			scanf("%d",&p);
			v1[p].push_back(i);
		}
		for (int i=2;i<=n;i++)
		{
			int p;
			scanf("%d",&p);
			v2[p].push_back(i);
		}
		ct=0;
		dfs1(1);
		ans=0;
		dfs2(1);
		printf("%d\n",ans);
	}
}