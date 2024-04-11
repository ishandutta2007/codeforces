#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int m,to[N][26],rk[N],n,a[N],f[N];
bool is[N];
int dfs(int u,int r)
{
	int sum=is[u]?1:0;
	if(is[u])f[u]=min(f[u],rk[u]+r+1);
	F(i,0,26)
	{
		int v=to[u][i];if(!v)continue;
		f[v]=f[u]+1;
		rk[v]=rk[u]+sum;
		sum+=dfs(v,min(r,f[u]-rk[u]));
	}
	return sum;
}
int main()
{
	read(m);
	F(i,1,m+1)
	{
		int x;char c;read(x);do c=getchar();while(c==' ');
		to[x][c-'a']=i;
	}
	read(n);
	F(i,0,n)read(a[i]),is[a[i]]=true;
	dfs(0,INF);
	F(i,0,n)printf("%d ",f[a[i]]);
	puts("");
	return 0;
}