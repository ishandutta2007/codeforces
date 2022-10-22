#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=10005,M=105,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
char e[N];
int p,m,/*max*/f[N][M/*minus*/],/*min*/g[N][M],sign=1;
int dfs(int l)
{
	int r=l,lc=l,op,rc;
	if((e[l]^48)<10)
	{
		f[l][0]=g[l][0]=e[l]-48;
		return ++r;
	}
	op=dfs(++lc);
	r=dfs(rc=op+1)+1;
	if(sign==1)
	F(i,0,m+1)
	{
		if(f[lc][i]==-INF)break;
		F(j,0,m+1-i)
		{
			if(f[rc][j]==-INF)break;
			f[l][i+j]=max(f[l][i+j],f[lc][i]+f[rc][j]);
			g[l][i+j]=min(g[l][i+j],g[lc][i]+g[rc][j]);
			if(i+j+1>m)break;
		f[l][i+j+1]=max(f[l][i+j+1],f[lc][i]-g[rc][j]);
		g[l][i+j+1]=min(g[l][i+j+1],g[lc][i]-f[rc][j]);
		}
	}
	else
	F(i,0,m+1)
	{
		if(f[lc][i]==-INF)break;
		F(j,0,m+1-i)
		{
			if(f[rc][j]==-INF)break;
			f[l][i+j]=max(f[l][i+j],f[lc][i]-g[rc][j]);
			g[l][i+j]=min(g[l][i+j],g[lc][i]-f[rc][j]);
			if(i+j+1>m)break;
		f[l][i+j+1]=max(f[l][i+j+1],f[lc][i]+f[rc][j]);
		g[l][i+j+1]=min(g[l][i+j+1],g[lc][i]+g[rc][j]);
		}
	}
	return r;
}
int main()
{
	gets(e);
	read(p);read(m);
	if(p<m)swap(p,m),sign=-1;
	for(int i=0;e[i];++i)F(j,0,m+1)f[i][j]=-(g[i][j]=INF);
	dfs(0);
	printf("%d\n",f[0][m]);
	return 0;
}