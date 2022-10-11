#include <iostream>
using namespace std;
int n,m;
int ans[1005][1005],o[1005][1005][2];
char arr[1005][1005];
bool vis[1005][1005];
int flood(int ci,int cx,int oi,int ox)
{
	if (ci<0 || cx<0 || ci>=n || cx>=m)
	return 0;
	if (arr[ci][cx]=='*')
	return 1;
	if (vis[ci][cx])
	return 0;
	vis[ci][cx]=1;
	o[ci][cx][0]=oi;
	o[ci][cx][1]=ox;
	int ans=0;
	ans+=flood(ci+1,cx,oi,ox);
	ans+=flood(ci-1,cx,oi,ox);
	ans+=flood(ci,cx+1,oi,ox);
	ans+=flood(ci,cx-1,oi,ox);
	return ans;
}
int main()
{
	int k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
	{
		getchar();
		for (int x=0;x<m;x++)
		arr[i][x]=getchar();
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		{
			if (!vis[i][x] && arr[i][x]=='.')
			ans[i][x]=flood(i,x,i,x);
		}
	}
	while (k--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",ans[o[a-1][b-1][0]][o[a-1][b-1][1]]);
	}
}