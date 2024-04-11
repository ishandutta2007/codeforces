#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,u[N*N],v[N*N],w[N*N],f[N][N],out[N][N];
int main()
{
	read(n);read(m);
	F(i,0,n)F(j,0,n)f[i][j]=INF;
	F(i,0,n)f[i][i]=0;
	F(i,0,m)
	{
		read(u[i]);read(v[i]);read(w[i]);
		f[--u[i]][--v[i]]=w[i];f[v[i]][u[i]]=w[i];
	}
	F(k,0,n)F(i,0,n)F(j,0,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	F(e,0,m)
	{
		F(i,0,n)if(f[u[e]][i]==w[e]+f[v[e]][i])++out[u[e]][i];
		F(i,0,n)if(f[v[e]][i]==w[e]+f[u[e]][i])++out[v[e]][i];
	}
	F(i,0,n)F(j,i+1,n)
	{
		int ans=0;
		F(k,0,n)if(f[i][k]+f[k][j]==f[i][j])ans+=out[k][j];
		printf("%d ",ans);
	}
	puts("");
	return 0;
}