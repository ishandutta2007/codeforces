#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int x[2][140000],y[2][140000];
int n;
int sx[2][140000],sy[2][140000],gx[2][140000],gy[2][140000];
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x[0][i],&y[0][i],&x[1][i],&y[1][i]);
	}
	sx[0][0]=sy[0][0]=-1e9;
	sx[1][0]=sy[1][0]=1e9;
	for(int i=0;i<n;i++)
	{
		sx[0][i+1]=max(sx[0][i],x[0][i]);
		sy[0][i+1]=max(sy[0][i],y[0][i]);
		sx[1][i+1]=min(sx[1][i],x[1][i]);
		sy[1][i+1]=min(sy[1][i],y[1][i]);
	}
	gx[0][n]=gy[0][n]=-1e9;
	gx[1][n]=gy[1][n]=1e9;
	for(int i=n;i--;)
	{
		gx[0][i]=max(gx[0][i+1],x[0][i]);
		gy[0][i]=max(gy[0][i+1],y[0][i]);
		gx[1][i]=min(gx[1][i+1],x[1][i]);
		gy[1][i]=min(gy[1][i+1],y[1][i]);
	}
	for(int i=0;i<n;i++)
	{
		int nx[2],ny[2];
		nx[0]=max(sx[0][i],gx[0][i+1]);
		nx[1]=min(sx[1][i],gx[1][i+1]);
		ny[0]=max(sy[0][i],gy[0][i+1]);
		ny[1]=min(sy[1][i],gy[1][i+1]);
		if(nx[0]<=nx[1]&&ny[0]<=ny[1])
		{
			printf("%d %d\n",nx[0],ny[0]);
			return 0;
		}
	}
}