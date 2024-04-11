#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,f[N][N],g[N];
char s[N],p[N];
int main()
{
	scanf("%s%s",s,p);
	while(s[n])++n;while(p[m])++m;
	F(i,0,n)g[i]=-1;
	F(i,0,n)
	{
		int j=0;
		F(k,i,n)if(s[k]==p[j]&&(++j)==m)g[i]=++k,k=n;
	}
	F(i,0,n+1)F(j,0,n+1)f[i][j]=-INF;
	f[0][0]=0;
	F(i,0,n)
	{
		if(~g[i])F(j,0,n-g[i]+i+m)f[g[i]][j+g[i]-i-m]=f[i][j]+1;
		F(j,0,n+1)f[i+1][j]=f[i+1][j]>f[i][j]?f[i+1][j]:f[i][j];
		F(j,0,n)f[i+1][j+1]=f[i+1][j+1]>f[i][j]?f[i+1][j+1]:f[i][j];
	}
	F(i,0,n+1)printf("%d ",f[n][i]);
	printf("\n");
	return 0;
}