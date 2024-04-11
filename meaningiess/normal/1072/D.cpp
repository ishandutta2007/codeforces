#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
char ans[5000],map[2020][2020],r[5000];
int f[2020][2020],g[4020][4020];queue<int> q;
int main()
{
	int n,i,j,k,mx=0,p1=1,p2=1,cnt=0,w=0;cin>>n>>k;for (i=1;i<=n;i++) scanf("%s",map[i]+1);
	if (k==0)
	{
		g[1][1]=1;
		for (i=1;i<=n*2-1;i++)
		{
			cnt=0;for (j=1;j<=i;j++) if (j<=n && i-j+1<=n && g[j][i-j+1]) r[++cnt]=map[j][i-j+1];
			sort(r+1,r+cnt+1);cout<<r[1];
			for (j=1;j<=i;j++) if (g[j][i-j+1] && map[j][i-j+1]==r[1]) g[j+1][i-j+1]=g[j][i-j+1+1]=1;
		}
		return 0;
	}
	for (i=1;i<=n;i++) for (j=1;j<=n;j++)
	{
		if (map[i][j]=='a') f[i][j]=1;
		f[i][j]+=max(f[i-1][j],f[i][j-1]);
		if (i+j-1-f[i][j]<=k && i+j-1>mx) mx=i+j-1;
	}
	for (i=1;i<mx;i++) cout<<'a';
	for (i=1;i<=mx;i++) if (i<=n && mx-i+1<=n && mx-f[i][mx-i+1]<=k) map[i][mx-i+1]='a',g[i][mx-i+1]=1;
	for (i=mx;i<=n*2-1;i++)
	{
		cnt=0;for (j=1;j<=i;j++) if (j<=n && i-j+1<=n && g[j][i-j+1]) r[++cnt]=map[j][i-j+1];
		sort(r+1,r+cnt+1);cout<<r[1];
		for (j=1;j<=i;j++) if (g[j][i-j+1] && map[j][i-j+1]==r[1]) g[j+1][i-j+1]=g[j][i-j+1+1]=1;
	}
}