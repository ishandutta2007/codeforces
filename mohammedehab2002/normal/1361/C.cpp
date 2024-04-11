#include <bits/stdc++.h>
using namespace std;
bool used[1000005];
vector<int> v[(1<<20)],ans;
int a[1000005],b[1000005];
void dfs(int i,bool p)
{
	used[i]=1;
	if (p)
	{
		while (1)
		{
			while (!v[b[i]].empty() && used[v[b[i]].back()])
			v[b[i]].pop_back();
			if (v[b[i]].empty())
			break;
			dfs(v[b[i]].back(),0);
		}
	}
	else
	dfs((i^1),1);
	ans.push_back(i);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<2*n;i++)
	scanf("%d",&a[i]);
	for (int i=20;i>=0;i--)
	{
		for (int j=0;j<2*n;j++)
		{
			b[j]=(a[j]&((1<<i)-1));
			v[b[j]].push_back(j);
		}
		dfs(0,0);
		if (ans.size()==2*n && b[ans[0]]==b[ans.back()])
		{
			printf("%d\n",i);
			for (int j:ans)
			printf("%d ",j+1);
			return 0;
		}
		for (int j=0;j<2*n;j++)
		v[b[j]].clear();
		memset(used,0,sizeof(used));
		ans.clear();
	}
}