#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1010;
int n,m,a[MAXN],x,y;
double f[MAXN][MAXN],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j]) f[i][j]=1;
			else f[i][j]=0;
	for(int T=1;T<=m;T++)
	{
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		for(int i=1;i<x;i++)
		{
			double con=f[i][x]+f[i][y];
			f[i][x]=f[i][y]=con/2;
		}
		for(int i=x+1;i<y;i++)
		{
			double con=f[i][y]+1-f[x][i];
			f[i][y]=con/2;
			f[x][i]=1-f[i][y];
		}
		for(int i=y+1;i<=n;i++)
		{
			double con=f[x][i]+f[y][i];
			f[x][i]=f[y][i]=con/2;
		}
		f[x][y]=0.5;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=f[i][j];
	printf("%.010lf\n",ans);
	return 0;
}