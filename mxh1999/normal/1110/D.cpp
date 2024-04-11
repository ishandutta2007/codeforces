#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;
int a[maxn];
int f[maxn][3][5];
int n,m;

int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	memset(f,-1,sizeof(f));
	for (int i=0;i<3;i++)
	if (i<=a[1] && (a[1]-i)%3==0)
		for (int j=0;j<5;j++)
		if (j<=a[2] && (a[2]-j)%3==0)
			f[2][i][j]=(a[1]-i)/3+(a[2]-j)/3;
	for (int i=2;i<n;i++)
		for (int x=0;x<3;x++)
			for (int y=0;y<5;y++)
			if (~f[i][x][y])
				for (int q=0;q<3 && q<=x && q<=y;q++)
				{
					for (int z=0;z<5 && z<=a[i+1]-q;z++)
					{
						int k=(a[i+1]-q-z)/3;
						int _y=y-q;
						if (_y>2)	_y=2;
						f[i+1][_y][z]=max(f[i+1][_y][z],f[i][x][y]+k+q);
					}
				}
	int ans=0;
	for (int i=0;i<3;i++)
		for (int j=0;j<5;j++)
			ans=max(ans,f[n][i][j]);
	printf("%d\n",ans);
	return 0;
}