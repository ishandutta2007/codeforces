#include<bits/stdc++.h>
#define N 505
using namespace std;
int a[N][N],b[N][N];
int main()
{
	int n,m,i,j;scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&b[i][j]);
	for (i=1;i<n;i++)
	{
		for (j=1;j<m;j++)
		{
			if (a[i][j]) a[i][j]^=1,a[i+1][j]^=1,a[i][j+1]^=1,a[i+1][j+1]^=1;
			if (b[i][j]) b[i][j]^=1,b[i+1][j]^=1,b[i][j+1]^=1,b[i+1][j+1]^=1;
		}
	}
	for (i=1;i<=n;i++) if (a[i][m]!=b[i][m]) {printf("NO");exit(0);}
	for (i=1;i<=m;i++) if (a[n][i]!=b[n][i]) {printf("NO");exit(0);}
	printf("YES");
}