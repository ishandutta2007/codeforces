//???
#include <bits/stdc++.h>
using namespace std;
#define N 20005
int n,m,c,lg[N],a[N],z[15][35][N],mx[35][15][N];
int w1[35],ans[N],w[N][35];struct Query {int l,r,x;}b[N];
int qMx(int l,int r,int x)
{int t=lg[r-l+1];return max(mx[x][t][l],mx[x][t][r-(1<<t)+1]);}
int main()
{
	scanf("%d %d",&n,&m);for(int i=2;i<=n;++i) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		for(int j=0;j<=30;++j) z[0][j][i]=min(i+j+a[i],n);
	}
	for(int i=1;i<=14;++i) for(int j=0;j<=30;++j)
	{
		for(int k=1;k<=n;++k) mx[j][0][k]=z[i-1][j][k];
		for(int k=1;k<=14;++k) for(int l=1;l+(1<<k)-1<=n;++l)
			mx[j][k][l]=max(mx[j][k-1][l],mx[j][k-1][l+(1<<k-1)]);
		for(int k=0;k<=j;++k) for(int l=1;l<=n;++l)
			z[i][j][l]=max(z[i][j][l],qMx(l,z[i-1][k][l],j-k));
	}
	for(int i=1,l,r,x;i<=m;++i)
	{
		scanf("%d %d %d",&l,&r,&x);b[i]=(Query) {l,r,x};
		for(int j=0;j<=x;++j) w[i][j]=l;if(l==r) --ans[i];
	}
	for(int i=14;i>=0;--i)
	{
		for(int j=0;j<=30;++j)
		{
			for(int k=1;k<=n;++k) mx[j][0][k]=z[i][j][k];
			for(int k=1;k<=14;++k) for(int l=1;l+(1<<k)-1<=n;++l)
				mx[j][k][l]=max(mx[j][k-1][l],mx[j][k-1][l+(1<<k-1)]);
		}
		for(int j=1;j<=m;++j)
		{
			for(int k=0;k<=b[j].x;++k) w1[k]=b[j].l;
			for(int k=0;k<=b[j].x;++k) for(int l=0;l<=k;++l)
				w1[k]=max(w1[k],qMx(b[j].l,w[j][l],k-l));
			if(w1[b[j].x]<b[j].r)
			{for(int k=0;k<=b[j].x;++k) w[j][k]=w1[k];ans[j]|=1<<i;}
		}
	}for(int i=1;i<=m;++i) printf("%d\n",ans[i]+1);return 0;
}