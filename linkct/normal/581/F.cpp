#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=5000+10;
const int INF=200000000;
int f[maxn][maxn]; 
vector<int>pic[maxn];
int siz[maxn];
void solve(int root,int fa)
{
	f[root][0]=0;
	if (pic[root].size()==1)
	{
		siz[root]=1;
		return;
	}
	for (int i=0;i<pic[root].size();i++)
	{
		int v=pic[root][i];
		if (v==fa) continue;
		solve(v,root);
	}
	for (int i=0;i<pic[root].size();i++)
	{
		int v=pic[root][i];
		if (v==fa) continue;
		for (int j=siz[root]+siz[v];j>0;j--)
		for (int k=0;k<=j&&k<=siz[v];k++)
		{
			//if (k!=siz[v])
		//	{
				f[root][j]=min(f[root][j],f[root][j-k]+f[v][k]); 
				f[root][j]=min(f[root][j],f[root][j-k]+f[v][siz[v]-k]+1);
			//}
			//else f[root][j]=min(f[root][j],f[root][j-k]+1);
		}
		siz[root]+=siz[v];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		pic[x].push_back(y);
		pic[y].push_back(x);
	}
	if (n==2)
	{
		printf("1\n");
		return 0;
	}
	int root=0;
	for (int i=1;i<=n;i++)
	if (pic[i].size()>=2)
	{
		root=i;
		break;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	f[i][j]=INF;
	solve(root,-1);
	printf("%d\n",f[root][siz[root]/2]);
	return 0;
}