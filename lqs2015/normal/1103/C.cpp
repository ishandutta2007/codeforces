#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,k,x,y,dep[333333],ct,pa[333333];
vector<int> g[333333],gg[333333]; 
bool used[333333];
vector<int> gf[333333],v;
void dfs(int i,int fa)
{
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (!used[to])
		{
			dfs(to,i);
			gg[i].push_back(to); 
		}
		else
		{
			gf[i].push_back(to); 
		}
	}
}
void dft(int i,int deep)
{
	dep[i]=deep;v.push_back(i); 
	if (deep>=(n+k-1)/k)
	{
		printf("PATH\n");
		printf("%d\n",(n+k-1)/k);
		for (int i=0;i<(n+k-1)/k;i++) printf("%d ",v[i]);
		printf("\n");
		exit(0);
	}
	for (int j=0;j<gg[i].size();j++)
	{
		int to=gg[i][j];
		pa[to]=i;
		dft(to,deep+1);
		v.pop_back();
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0);
	dft(1,1);
	printf("CYCLES\n");
	for (int i=1;i<=n;i++)
	{
		if (!gg[i].size())
		{
			ct++;
			if (dep[i]-dep[gf[i][0]]+1>3 && (dep[i]-dep[gf[i][0]]+1)%3)
			{
				int cur=i;
				printf("%d\n",dep[i]-dep[gf[i][0]]+1);
				while(cur!=gf[i][0])
				{
					printf("%d ",cur);
					cur=pa[cur];
				}
				printf("%d\n",cur);
			}
			else if (dep[i]-dep[gf[i][1]]+1>3 && (dep[i]-dep[gf[i][1]]+1)%3)
			{
				int cur=i;
				printf("%d\n",dep[i]-dep[gf[i][1]]+1);
				while(cur!=gf[i][1])
				{
					printf("%d ",cur);
					cur=pa[cur];
				}
				printf("%d\n",cur);
			}
			else
			{
				if (dep[gf[i][0]]<dep[gf[i][1]]) swap(gf[i][0],gf[i][1]);
				printf("%d\n",dep[gf[i][0]]-dep[gf[i][1]]+2);
				printf("%d ",i);
				int cur=gf[i][0];
				while(cur!=gf[i][1])
				{
					printf("%d ",cur);
					cur=pa[cur];
				}
				printf("%d\n",cur);
			}
			if (ct==k) break;
		}
	}
	return Accepted;
}