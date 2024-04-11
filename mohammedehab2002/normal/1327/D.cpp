#include <bits/stdc++.h>
using namespace std;
int p[200005],col[200005];
bool vis[200005],ok[200005];
vector<int> c;
void dfs(int i)
{
	vis[i]=1;
	c.push_back(i);
	if (!vis[p[i]])
	dfs(p[i]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		int ans=n;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			vis[i]=0;
		}
		for (int i=1;i<=n;i++)
		scanf("%d",&col[i]);
		for (int i=1;i<=n;i++)
		{
			if (!vis[i])
			{
				c.clear();
				dfs(i);
				for (int j=1;j<=c.size();j++)
				{
					if (c.size()%j==0)
					{
						for (int k=0;k<j;k++)
						ok[k]=1;
						for (int k=0;k<c.size();k++)
						ok[k%j]&=(col[c[k]]==col[c[k%j]]);
						for (int k=0;k<j;k++)
						{
							if (ok[k])
							ans=min(ans,j);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}