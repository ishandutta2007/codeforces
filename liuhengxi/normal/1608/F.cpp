#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define add(x,y) (x=(int)((x+(y))%MOD))
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
constexpr int N=2005,MOD=998244353;
int &reduce(int &x){(x>=MOD)&&(x-=MOD);return x;}
int n,k,l,r,ll,rr,f[105][N],g[105][N],h[N][N],P[N][N],ans;
int main()
{
	read(n,k);
	F(i,0,n+1)P[i][0]=1;
	F(i,1,n+1)F(j,1,i+1)P[i][j]=(int)(P[i-1][j-1]*(long long)i%MOD);
	ll=0;rr=1;
	f[0][0]=1;
	F(i,0,n)
	{
		int b;read(b);
		l=max(b-k,0);
		r=min(b+k,i+1)+1;
		if(l>=r)return puts("0"),0;
		memset(g,0,sizeof(int)*N*(2*k+2));
		F(j,max(l,ll),min(r,rr))F(p,0,min(i,n-j)+1)
		{
			add(g[j-l][p],f[j-ll][p]*(long long)(j+p));
			reduce(g[j-l][p+1]+=f[j-ll][p]);
		}
		if(ll+1<r)
		{
			memset(h[ll],0,sizeof(int)*N*(r-ll));
			F(j,ll+1,r)F(p,0,i+1)
			{
				if(j<=rr)h[j][p]=f[j-ll-1][p];
				add(h[j][p],h[j-1][p+1]*(p+1ll));
				if(j>=l)reduce(g[j-l][p]+=h[j][p]);
			}
		}
		memcpy(f,g,sizeof(int)*N*(2*k+2));
		ll=l;rr=r;
	}
	F(i,l,r)F(j,0,n-i+1)add(ans,f[i-l][j]*(long long)P[n-i][j]);
	printf("%d\n",ans);
	return 0;
}