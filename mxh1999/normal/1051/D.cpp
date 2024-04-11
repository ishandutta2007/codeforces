#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
const int mo=998244353;
int a[1010][2010][4];
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	a[1][1][0]=1;a[1][2][1]=1;a[1][2][2]=1;a[1][1][3]=1;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=0;k<4;k++)
			if (a[i-1][j][k])
			{
				int cost;
				if (k==3)	cost=1;else cost=0;
				if (j+cost<=m)	(a[i][j+cost][0]+=a[i-1][j][k])%=mo;
				cost=2;
				if (k&1)	cost--;
				if (!(k&2))	cost--;
				if (j+cost<=m)	(a[i][j+cost][1]+=a[i-1][j][k])%=mo;
				cost=2;
				if (!(k&1))	cost--;
				if ((k&2))	cost--;
				if (j+cost<=m)	(a[i][j+cost][2]+=a[i-1][j][k])%=mo;
				if (k==0)	cost=1;else cost=0;
				if (j+cost<=m)	(a[i][j+cost][3]+=a[i-1][j][k])%=mo;
			}
	int ans=0;
	for (int i=0;i<4;i++)
		(ans+=a[n][m][i])%=mo;
	printf("%d\n",ans);
	return 0;
}