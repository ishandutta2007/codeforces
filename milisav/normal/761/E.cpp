#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> a[40];
int x[40],y[40];
bool tk[40][4];
bool vs[40];
void dfs(int u, int k)
{
	int v;
	vs[u]=true;
	for(int i=0;i<a[u].size();i++)
	{
		v=a[u][i];
		if(!vs[v])
		{
			if(!tk[u][0])
			{
				x[v]=x[u];
				y[v]=y[u]+k;
				tk[u][0]=true;
				tk[v][2]=true;
				dfs(v,k/2);
			}
			else
			{
				if(!tk[u][1])
				{
					x[v]=x[u]-k;
					y[v]=y[u];
					tk[u][1]=true;
					tk[v][3]=true;
					dfs(v,k/2);
				}
				else
				{
					if(!tk[u][2])
					{
						x[v]=x[u];
						y[v]=y[u]-k;
						tk[u][2]=true;
						tk[v][0]=true;
						dfs(v,k/2);
					}
					else
					{
						x[v]=x[u]+k;
						y[v]=y[u];
						tk[u][3]=true;
						tk[v][1]=true;
						dfs(v,k/2);
					}
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		u--;
		v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		tk[i][0]=false;
		tk[i][1]=false;
		tk[i][2]=false;
		tk[i][3]=false;
		vs[i]=false;
		if(a[i].size()>4)
		{
			printf("NO");
			return 0;
		}
	}
	int k=1073741824;
	x[0]=0;
	y[0]=0;
	printf("YES\n");
	dfs(0,k);
	for(int i=0;i<n;i++) printf("%d %d\n",x[i],y[i]);
	return 0;
}