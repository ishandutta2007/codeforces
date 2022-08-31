#include<cstdio>
#include<iostream>

using namespace std;

const int MaxM=310;
const int MaxN=3010;

int n,m;
long double p[MaxM][MaxN],F[MaxM][MaxN],d[MaxM],c[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			int x;
			scanf("%d",&x);
			p[j][i]=x*(long double)0.001;
		}
	for (int i=1;i<=m;++i)
	{
		F[i][0]=1;
		for (int j=1;j<=n;++j)
			F[i][j]=F[i][j-1]*(1-p[i][j]);
		d[i]=1-F[i][n];
	}
	long double ans=0;
	for (int i=1;i<=n;++i)
	{
		int get=1;
		for (int j=2;j<=m;++j)
			if (d[get]<d[j]) get=j;
		ans+=d[get];
		for (int j=1;j<=n;++j)
			c[j]=c[j-1]*(1-p[get][j])+F[get][j-1]*p[get][j];
		for (int j=0;j<=n;++j)
			F[get][j]=c[j];
		d[get]-=F[get][n];
	}
	printf("%.12lf\n",(double)ans);
	return 0;
}