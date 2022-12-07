#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int INF=1000000000;
int n,d,a[110],x[110],y[110],dis[110][110];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=2;i<n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*d-a[j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	printf("%d\n",dis[1][n]);
	return 0;
}