#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=10005,K=25,INF=0x3f3f3f3f;
int n,k,l,x[N],dis[N],a[N],g[K][K],f[(1<<20)+5],q[N],qf,qr;
int main()
{
	read(n,k,l);
	++n;
	F(i,0,k)
	{
		--read(x[i<<1]);
		x[i<<1|1]=x[i<<1]+1;
	}
	k<<=1;
	F(i,0,l)read(a[i]);
	memset(f,0x3f,sizeof f);
	f[0]=0;
	F(i,0,k)
	{
		F(j,0,n)dis[j]=INF;
		dis[x[i]]=0;
		qf=qr=0;q[qr++]=x[i];
		while(qf<qr)
		{
			int u=q[qf++];
			F(j,0,l)
			{
				int v=u-a[j];
				if(v>=0&&dis[v]==INF)dis[q[qr++]=v]=dis[u]+1;
				v=u+a[j];
				if(v<n&&dis[v]==INF)dis[q[qr++]=v]=dis[u]+1;
			}
		}
		F(j,0,k)if(j!=i)f[1<<i|1<<j]=dis[x[j]];
	}
	F(i,3,1<<k)if(!__builtin_parity(i))
	{
		int u=__builtin_ctz(i);
		F(v,u+1,k)if(i>>v&1)f[i]=min(f[i],f[i^1<<u^1<<v]+f[1<<u|1<<v]);
	}
	if(f[(1<<k)-1]==INF)f[(1<<k)-1]=-1;
	printf("%d\n",f[(1<<k)-1]);
	return 0;
}