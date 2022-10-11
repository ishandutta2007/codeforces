#include <iostream>
#include <vector>
using namespace std;
int s[100005],r[100005],col[100005];
vector<pair<int,int> > v[100005];
bool ok=1;
void dfs(int node,int c)
{
	if (col[node] && col[node]!=c+1)
	ok=0;
	if (col[node])
	return;
	col[node]=c+1;
	for (int i=0;i<v[node].size();i++)
	dfs(v[node][i].first,(c^v[node][i].second)^1);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&s[i]);
	for (int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		while (x--)
		{
			int a;
			scanf("%d",&a);
			if (r[a])
			{
				v[i].push_back(make_pair(r[a],s[a]));
				v[r[a]].push_back(make_pair(i,s[a]));
			}
			else
			r[a]=i;
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (!col[i])
		dfs(i,0);
	}
	printf(ok? "YES":"NO");
}