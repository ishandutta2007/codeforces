#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
int arr[100005],ans[100005];
map<int,vector<int> > m;
map<int,bool> e;
vector<int> v;
bool vis[100005];
int a,b;
void dfs(int x)
{
	if (vis[x] || m[arr[x]].size()==0)
	return;
	vis[x]=1;
	v.push_back(x);
	e[arr[x]]=1;
	vector<int> va=m[a-arr[x]],vb=m[b-arr[x]];
	for (int i=0;i<va.size();i++)
	dfs(va[i]);
	for (int i=0;i<vb.size();i++)
	dfs(vb[i]);
}
int main()
{
	int n;
	scanf("%d%d%d",&n,&a,&b);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		m[arr[i]].push_back(i);
	}
	for (int i=0;i<n;i++)
	{
		e.clear();
		v.clear();
		if (vis[i])
		continue;
		dfs(i);
		bool ca=1,cb=1;
		for (int x=0;x<v.size();x++)
		{
			if (!e[a-arr[v[x]]])
			ca=0;
			if (!e[b-arr[v[x]]])
			cb=0;
		}
		int s=-1;
		if (ca)
		s=0;
		if (cb)
		s=1;
		if (s==-1)
		{
			puts("NO");
			return 0;
		}
		for (int x=0;x<v.size();x++)
		ans[v[x]]=s;
	}
	puts("YES");
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}