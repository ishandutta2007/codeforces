#include <iostream>
#include <vector>
#include <set>
using namespace std;
int par[200005],f[200005];
vector<int> v[200005];
bool e[200005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x!=y)
	par[x]=y;
}
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	while (q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		e[b]=1;
	}
	for (int i=n;i>0;i--)
	{
		par[i]=i;
		for (int x:v[i])
		f[x]=i;
	}
	for (int i=1;i<=n;i++)
	{
		for (int x:v[i])
		Union(i,f[x]);
	}
	set<int> tmp;
	for (int i=1;i<=n;i++)
	tmp.insert(find(i));
	int ans=tmp.size()-1;
	for (int i=1;i<=m;i++)
	ans+=!e[i];
	printf("%d\n",ans);
}