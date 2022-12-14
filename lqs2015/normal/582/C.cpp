#pragma GCC optimize("Ofast,no-stack-protector,inline")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("arch=corei7-avx")
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,p=1e6+7;
int a[555555],has[555555],cur,anp,b[222222],pw[555555],fck;
int pre[222222],dp[444444],n,i,j,k,x;
long long ans;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
struct fastio
{
	char s[300000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,300000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
inline int getnum()
{
	int r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
int main()
{
	n=getnum();
	for (i=1;i<=n;i++)
	{
		a[i]=getnum();
		a[n+i]=a[i];
	}
	pw[0]=1;
	for (i=1;i<=2*n;i++) pw[i]=1ll*pw[i-1]*p%mod;
	for (i=1;i<=2*n;i++)
	{
		has[i]=(1ll*has[i-1]*p+a[i])%mod;
	}
	for (i=1;i<=n;i++)
	{
		if (n%i==0)
		{
			x=n/i-1;
			for (j=1;j<=x;j++)
			{
				pre[j]=pre[j-1]+(gcd(j,n/i)==1);
			}
			cur=0;
			for (j=1;j<=i;j++)
			{
				anp=0;
				for (k=j;k<=n;k+=i)
				{
					if (anp<a[k]) anp=a[k];
				}
				b[j]=anp;
			}
			for (j=1;j<=i;j++) cur=(1ll*cur*p+b[j])%mod;
			memset(dp,0,sizeof(dp));
			for (j=1;j<=i;j++)
			{
				for (k=(n<<1)-(i<<1)+j;k>=1;k-=i)
				{
					fck=(1ll*has[k+i-1]-1ll*has[k-1]*pw[i])%mod+mod;
					if (fck>=mod) fck-=mod;
					if (fck==cur) 
					{
						if (dp[k+i]==x) dp[k]=x;
						else dp[k]=dp[k+i]+1;
					}
					else dp[k]=0;
				}
				cur=(((1ll*cur-1ll*pw[i-1]*b[j])%mod)*p+b[j])%mod;
				cur=(cur+mod)%mod;
			}
			for (j=1;j<=n;j++)
			{
				ans+=1ll*pre[dp[j]];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}