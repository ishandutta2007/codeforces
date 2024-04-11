#include<bits/stdc++.h>
using namespace std;
int n,a[15][15];
int main()
{
	scanf("%d",&n),memset(a,0,sizeof(a));
	for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),a[x][y]=a[y][x]=1;
	for(int i=1;i<=5;i++)
		for(int j=i+1;j<=5;j++)
			for(int k=j+1;k<=5;k++)
				if((a[i][j]&&a[j][k]&&a[k][i])||(!a[i][j]&&!a[j][k]&&!a[k][i]))
					return puts("WIN"),0;
	return puts("FAIL"),0;
}