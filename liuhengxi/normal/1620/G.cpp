#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define popcount __builtin_popcount
#define ctz __builtin_ctz
#define parity __builtin_parity
using namespace std;
const int N=30,M=2e4+5,K=(1<<23)+5,MOD=998244353;
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
int n,c[N][N],f[K][N],p[K];
long long ans;
char s[M];
int main()
{
	read(n);
	F(i,0,n)
	{
		char *t;
		scanf("%s",s);
		t=s;
		for(int j=0;j<26;t+=c[i][j++])while(t[c[i][j]]==j+'a')++c[i][j];
	}
	F(i,1,1<<n)
	{
		int j=ctz(i);
		p[i]=1;
		if(popcount(i)==1)F(k,0,26)f[i][k]=c[j][k];
		else F(k,0,26)f[i][k]=min(f[i^1<<j][k],c[j][k]);
		F(k,0,26)p[i]=int((f[i][k]+1ll)*p[i]%MOD);
		if(!parity(i))p[i]=(p[i]?MOD:0)-p[i];
	}
	F(b,0,n)
	{
		int k=1<<b;
		F(i,0,1<<n)if(i&k)
		{
			p[i]+=p[i^k];
			if(p[i]>=MOD)p[i]-=MOD;
		}
	}
	F(i,1,1<<n)
	{
		long long d=0;
		F(j,0,n)if(i>>j&1)d+=j+1;
		d*=popcount(i);
		ans^=d*p[i];
	}
	printf("%lld\n",ans);
	return 0;
}