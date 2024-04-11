#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=405,M=605,INF=0x3fffffff,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,f[N][N],u[M],v[M],p[N];
int calc(int dis,int x[N],int y[N])
{
	int cnt=0;long long ans=1;
	F(i,0,n)cnt+=(p[i]=(x[i]+y[i]==dis));
	if(cnt!=dis+1)return 0;
	F(i,0,m)if((x[u[i]]-x[v[i]])*(y[u[i]]-y[v[i]])==1)++p[x[u[i]]>x[v[i]]?u[i]:v[i]];
	F(i,0,n)(ans*=p[i])%=MOD;
	return (int)(ans);
}
int main()
{
	read(n,m);
	F(i,0,n)F(j,0,n)f[i][j]=INF;
	F(i,0,n)f[i][i]=0;
	F(i,0,m)
	{
		--read(u[i]),--read(v[i]);
		f[u[i]][v[i]]=f[v[i]][u[i]]=1;
	}
	F(k,0,n)F(i,0,n)F(j,0,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	F(i,0,n)
	{
		F(j,0,n)printf("%d ",calc(f[i][j],f[i],f[j]));
		puts("");
	}
	return 0;
}