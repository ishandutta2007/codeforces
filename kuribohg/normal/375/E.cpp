#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define next next2
using namespace std;
const int MAXN=510;
const double INF=1e10;
const double eps=1e-10;
int n,m,S,Len,col[MAXN];
int head[MAXN],to[MAXN<<1],next[MAXN<<1],w[MAXN<<1],cnt=1;
int out[MAXN],bas[MAXN];
double A[MAXN][MAXN],X[MAXN],ans;
inline void adde(int f,int t,int ww)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
void DFS(int x,int fa,int d,double A[])
{
	if(d<=Len) A[x]=-1;
	if(d>Len) return;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa) DFS(to[i],x,d+w[i],A);
}
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	return (x>0)?1:-1;
}
void Pivot(int a,int b)
{
	for(int i=0;i<=m;i++)
		if(i!=a&&sgn(A[i][b]))
		{
			for(int j=1;j<=n+1;j++)
				if(j!=b) A[i][j]-=A[a][j]*A[i][b]/A[a][b];
		}
	for(int j=1;j<=n+1;j++)
		if(j!=b) A[a][j]/=A[a][b];
	for(int i=0;i<=m;i++)
		if(i!=a) A[i][b]/=-A[a][b];
	A[a][b]=1/A[a][b];
	swap(bas[a],out[b]);
}
double Simplex()
{
	for(int i=1;i<=n;i++) A[0][i]=-A[0][i];
	for(int i=1;i<=m;i++) bas[i]=-i;
	for(int i=1;i<=n;i++) out[i]=i;
	while(true)
	{
		int ii=1,jj=1;
		for(int i=1;i<=m;i++)
			if(A[i][n+1]<A[ii][n+1]) ii=i;
		if(sgn(A[ii][n+1])>=0) break;
		for(int j=1;j<=n;j++)
			if(A[ii][j]<A[ii][jj]) jj=j;
		if(sgn(A[ii][jj])>=0) return -INF;
		Pivot(ii,jj);
	}
	while(true)
	{
		int ii=1,jj=1;
		for(int j=1;j<=n;j++)
			if(A[0][j]<A[0][jj]) jj=j;
		if(sgn(A[0][jj])>=0) break;
		for(int i=1;i<=m;i++)
			if(sgn(A[i][jj])>0&&(sgn(A[ii][jj])<=0||A[i][n+1]/A[i][jj]<A[ii][n+1]/A[ii][jj])) ii=i;
		if(sgn(A[ii][jj])<=0) return INF;
		Pivot(ii,jj);
	}
	for(int i=1;i<=m;i++) if(bas[i]>=0) X[bas[i]]=A[i][n+1];
	return A[0][n+1];
}
int main()
{
	scanf("%d%d",&n,&Len);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&col[i]);
		if(col[i]==1) S++;
		else A[0][i]=-1;
	}
	for(int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),adde(x,y,z);
	for(int i=1;i<=n;i++) DFS(i,-1,0,A[i]),A[i][n+1]=-1;
	m=n+1;
	for(int i=1;i<=n;i++) A[m][i]=1;
	A[m][n+1]=S;
	ans=-Simplex();
	if(ans>1e9) puts("-1");
	else printf("%d\n",(int)(ans+0.5));
	return 0;
}