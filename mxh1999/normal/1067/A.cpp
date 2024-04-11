#include<bits/stdc++.h>
using namespace std;

const int mo=998244353;
const int maxn=100010;
int f[maxn][210][3];//0:a[i]<a[i-1] 1:a[i]=a[i-1] 2:a[i]>a[i-1]
int n;
int a[maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (a[1]!=-1)	f[1][a[1]][2]=1;
	else for (int i=1;i<=200;i++)	f[1][i][2]=1;
	for (int i=2;i<=n;i++)
	{
		int tot=0;
		for (int j=200;j>=1;j--)
		{
			f[i][j][0]=tot;
			tot=((tot+f[i-1][j][1])%mo+f[i-1][j][0])%mo;
		}
		for (int j=1;j<=200;j++)
			f[i][j][1]=((f[i-1][j][0]+f[i-1][j][1])%mo+f[i-1][j][2])%mo;
		tot=0;
		for (int j=1;j<=200;j++)
		{
			f[i][j][2]=tot;
			tot=((tot+f[i-1][j][0])%mo+(f[i-1][j][1]+f[i-1][j][2])%mo)%mo;
		}
		if (i==2)
		{
			for (int j=1;j<=200;j++)
				f[i][j][0]=0;
		}
		if (a[i]!=-1)
			for (int j=1;j<=200;j++)
				if (j!=a[i])	f[i][j][0]=f[i][j][1]=f[i][j][2]=0;
	}
	int ans=0;
	for (int j=1;j<=200;j++)
		ans=((ans+f[n][j][0])%mo+f[n][j][1])%mo;
	printf("%d\n",ans);
	return 0;
}