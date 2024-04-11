#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1505,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,a[N][N],f[N<<1],son[N<<1][2],eu[N*N>>1],ev[N*N>>1],s[N<<1][N],siz[N<<1],edge[N<<1];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(n);m=n*(n-1)>>1;
	F(i,0,n)F(j,0,n)--read(a[i][j]);
	F(i,0,n)F(j,0,i)eu[a[i][j]]=i,ev[a[i][j]]=j;
	F(i,0,n)s[i][1]=1,siz[i]=1;
	F(i,0,(n<<1)-1)f[i]=i;
	F(k,0,m)
	{
		int u=eu[k],v=ev[k];
		u=find(u),v=find(v);
		if(u!=v)
		{
			f[son[n][0]=u]=n;
			f[son[n][1]=v]=n;
			siz[n]=siz[son[n][0]]+siz[son[n][1]];
			edge[n]=edge[son[n][0]]+edge[son[n][1]]+1;
			F(i,1,siz[u]+1)F(j,1,siz[v]+1)s[n][i+j]=(int)(((long long)s[u][i]*s[v][j]+s[n][i+j])%MOD);
			if(edge[n]==(siz[n]*(siz[n]-1)>>1))++s[n][1];
			++n;
		}
		else
		{
			++edge[u];
			if(edge[u]==(siz[u]*(siz[u]-1)>>1))++s[u][1];
		}
	}
	(++n)>>=1;
	F(i,1,n+1)printf("%d ",s[(n-1)<<1][i]);
	puts("");
	return 0;
}