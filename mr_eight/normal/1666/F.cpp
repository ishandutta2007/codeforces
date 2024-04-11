#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=5005,mod=998244353;
int t,n,a[N],nm[N],pw1[N],pw2[N],jc[N<<1],inv[N<<1],dp[N][N],sm[N][N],tg[N],tmp[N];

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

inline void init(int x)
{
	jc[0]=1;
	for(int i=1;i<=x;++i)
		jc[i]=jc[i-1]*i%mod;
	inv[x]=q_pow(jc[x],mod-2);
	for(int i=x-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
}

inline int C(int n,int m)
{
	return n<m?0:jc[n]*inv[m]%mod*inv[n-m]%mod;
}

signed main()
{
	init(10000);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				dp[i][j]=sm[i][j]=0;
		for(int i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		if(a[1]==a[2])
		{
			puts("0");
			continue;
		}
		a[n+1]=-1;
		pw1[0]=pw2[0]=1;
		int now=-1,nn=0;
		for(int i=1;i<=n;++i)
		{
			pw1[i]=pw2[i]=nm[i]=0;
			if(a[i]!=now)
				now=a[i],nn=1;
			else nn++;
			if(a[i]!=a[i+1])
			{
				tg[i]=1;nm[i]=nn;
				pw1[i]=pw1[i-nm[i]]*inv[nm[i]]%mod;
				pw2[i]=q_pow(pw1[i],mod-2);
			}
		}
		dp[1][0]=1;
		sm[1][0]=pw2[1];
		for(int i=2;i<=n;++i)
		{
			if(tg[i]==1)
			{
				for(int j=0;j<=n;++j)
					tmp[j]=0;
				for(int j=0;j<=n;++j)
					tmp[j]=sm[i-1][j]*inv[j]%mod*pw1[i-nm[i]]%mod*inv[nm[i]-1]%mod;
				for(int j=1;j<=n;++j)
					dp[i][j]=tmp[j-1];
			}
			for(int j=0;j<=n;++j)
				sm[i][j]=(sm[i-1][j+1]+dp[i][j]*jc[j]%mod*pw2[i]%mod)%mod;
		}
			
		int ans=0;
		for(int i=1;i<=n;++i)
			ans=(ans+dp[i][n-i-1]*jc[n-i]%mod*pw1[n]%mod*pw2[i]%mod)%mod;
		write(ans);puts("");
	}
	return 0;
}