#include <bits/stdc++.h>
using namespace std;
#define N 205
#define MOD 10007
int n,m,cnt,hlf,sz,ans;char a[N];
int id[N][N],dp[N][N*N];bool tg[N*N],vs[N][N*N];vector<int> e[N*N];
void W(int &x,int y) {x=(x+y)%MOD;}
struct Matrix
{
	int a[N*2][N*2];
	Matrix operator * (Matrix t)
	{
		Matrix res;
		for(int i=1;i<=sz;++i) for(int j=1;j<=sz;++j)
		{
			res.a[i][j]=0;
			for(int k=i;k<=j;++k) W(res.a[i][j],a[i][k]*t.a[k][j]);
		}return res;
	}
}X;
int DP(int x,int y)
{
	if(x<0) return 0;if(vs[x][y]) return dp[x][y];vs[x][y]=1;
	for(int i=0;i<e[y].size();++i) W(dp[x][y],DP(x-tg[y],e[y][i]));
	return dp[x][y];
}
Matrix qPow(Matrix x,int y)
{
	Matrix res;
	for(int i=1;i<=sz;++i) for(int j=1;j<=sz;++j) res.a[i][j]=(i==j);
	for(;y;y/=2,x=x*x) if(y&1) res=res*x;return res;
}
int main()
{
	scanf("%s %d",a+1,&n);m=strlen(a+1);
	for(int i=1;i<=m;++i) for(int j=i;j<=m;++j) id[i][j]=++cnt;++cnt;
	for(int i=1;i<=m;++i) for(int j=i;j<=m;++j)
		if(a[i]==a[j])
		{
			if(j-i<2) e[cnt].push_back(id[i][j]);
			else e[id[i+1][j-1]].push_back(id[i][j]);
		}
		else
		{
			tg[id[i][j]]=1;
			e[id[i+1][j]].push_back(id[i][j]);
			e[id[i][j-1]].push_back(id[i][j]);
		}hlf=(m+1)/2;sz=m+hlf*2-1;
	for(int i=0;i<m;++i) vs[i][id[1][m]]=1;dp[tg[id[1][m]]][id[1][m]]=1;
	for(int i=1;i<m;++i) X.a[i][i]=24;
	for(int i=0;i<hlf;++i)
		X.a[m+i][m+i]=25,X.a[m+hlf+i][m+hlf+i]=26,X.a[m+i][m+hlf+i]=1;
	for(int i=1;i<m+hlf-1;++i) X.a[i][i+1]=1;X=qPow(X,(n+m)/2);
	for(int i=0;i<m;++i) W(ans,X.a[m-i][m+hlf+(m-i+1)/2-1]*DP(i,cnt));
	if(n+m&1)
	{
		ans=ans*26%MOD;
		for(int i=1;i<=m;++i) for(int j=0;j<m;++j)
			W(ans,X.a[m-j][m+(m-j+1)/2-1]*DP(j,id[i][i]));
	}printf("%d\n",ans);return 0;
}