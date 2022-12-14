#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,p[111111],s[111111],x,a[111111];
long long ans;
vector<int> g[111111];
bool f;
void dfs(int i,int fa)
{
	a[i]=s[i]-s[fa];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (~s[to])
		{
			if (s[to]<s[i]) f=1;
		}
		else
		{
			if (g[to].size()==0) s[to]=s[i];
			else
			{
				int mn=2e9;
				for (int k=0;k<g[to].size();k++)
				{
					mn=min(mn,s[g[to][k]]);
				}
				s[to]=mn;
				if (s[to]<s[i]) f=1;
			}
		}
		dfs(to,i);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g[x].push_back(i); 
	}
	for (int i=1;i<=n;i++) scanf("%d",&s[i]);
	dfs(1,0);
	if (f) printf("-1\n");
	else 
	{
		for (int i=1;i<=n;i++) ans+=(long long)a[i];
		printf("%lld\n",ans);
	}
	return Accepted;
}