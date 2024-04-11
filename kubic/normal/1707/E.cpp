#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define clz __builtin_clz
int n,m,a[N],zL[18][18][N],zR[18][18][N];
int qryL(int x,int l,int r)
{
	int t=31-clz(r-l+1);
	return min(zL[x][t][l],zL[x][t][r-(1<<t)+1]);
}
int qryR(int x,int l,int r)
{
	int t=31-clz(r-l+1);
	return max(zR[x][t][l],zR[x][t][r-(1<<t)+1]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),zL[0][0][i]=zR[0][0][i]=x;
	for(int i=1;i<=17;++i) for(int j=1;j+(1<<i)-1<=n;++j)
	{
		zL[0][i][j]=min(zL[0][i-1][j],zL[0][i-1][j+(1<<i-1)]);
		zR[0][i][j]=max(zR[0][i-1][j],zR[0][i-1][j+(1<<i-1)]);
	}
	for(int i=1;i<=17;++i) for(int j=0;j<=17;++j)
		for(int k=1;k+(1<<j)-1<=n;++k)
		{
			zL[i][j][k]=qryL(i-1,zL[i-1][j][k],zR[i-1][j][k]);
			zR[i][j][k]=qryR(i-1,zL[i-1][j][k],zR[i-1][j][k]);
		}
	for(int i=1,l,r,l1,r1,res;i<=m;++i)
	{
		scanf("%d %d",&l,&r);res=1;
		if(l==1 && r==n) {printf("0\n");continue;}
		for(int j=17;j>=0;--j)
		{
			l1=qryL(j,l,r);r1=qryR(j,l,r);
			if(l1>1 || r1<n) l=l1,r=r1,res+=1<<j;
		}l1=qryL(0,l,r);r1=qryR(0,l,r);
		if(l1>1 || r1<n) res=-1;printf("%d\n",res);
	}return 0;
}