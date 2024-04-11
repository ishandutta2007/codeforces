#include <bits/stdc++.h>
using namespace std;
#define N 505
int n,a[N],ans[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,x,y;i<=n;++i)
	{
		x=y=i;ans[x][y]=a[i];
		for(int j=1;j<a[i];++j)
		{
			if(y>1 && !ans[x][y-1]) ans[x][--y]=a[i];
			else if(x<n && !ans[x+1][y]) ans[++x][y]=a[i];
			else {puts("-1");return 0;}
		}
	}
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=i;++j)
			printf("%d ",ans[i][j]);return 0;
}