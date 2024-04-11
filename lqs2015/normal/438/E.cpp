#include<bits/stdc++.h>
using namespace std; 
const long long mod=998244353;
long long s[888888],t[888888],a[888888],b[888888],c[888888],d[888888],g[888888];
long long n,m,sz,rev[888888],cnt,x;
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
void ntt(long long c[],long long flag)
{
	for (long long i=0;i<sz;i++)
	{
		if (rev[i]>i) swap(c[i],c[rev[i]]);
	}
	for (long long i=2;i<=sz;i<<=1)
	{
		for (long long j=0;j<sz;j+=i)
		{
			long long w,wn;
			w=1;
			if (flag==1) wn=binpow(3ll,(mod-1)/i);
			else wn=binpow(3ll,(mod-1)-(mod-1)/i);
			for (long long k=j;k<j+i/2;k++)
			{
				long long tmp1=c[k];
				long long tmp2=c[k+i/2]*w%mod;
				c[k]=(tmp1+tmp2)%mod;
				c[k+i/2]=(tmp1-tmp2)%mod;
				w=w*wn%mod;
			}
		}
	}
	if (flag==-1)
	{
		for (long long i=0;i<sz;i++)
		{
			c[i]=c[i]*binpow(sz,mod-2)%mod;
		}
	}
}
void mult(long long a[],long long b[],long long n,long long m)
{
	sz=1;cnt=0;
	while(sz<n+m) 
	{
		sz*=2;
		cnt++;
	} 
	rev[0]=0;
	for (long long i=1;i<sz;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
	}
	for (long long i=0;i<sz;i++) s[i]=t[i]=0;
	for (long long i=0;i<n;i++) s[i]=a[i];
	for (long long i=0;i<m;i++) t[i]=b[i];
	ntt(s,1);
	ntt(t,1);
	for (long long i=0;i<sz;i++) t[i]=s[i]*t[i]%mod;
	ntt(t,-1);
	for (long long i=0;i<sz;i++) b[i]=t[i];
}
void geti(long long a[],long long b[],long long n,long long m)
{
	sz=1;cnt=0;
	while(sz<2*n) 
	{
		sz*=2;
		cnt++;
	} 
	rev[0]=0;
	for (long long i=1;i<sz;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
	}
	for (long long i=0;i<sz;i++) s[i]=t[i]=0;
	for (long long i=0;i<n;i++) s[i]=a[i];
	for (long long i=0;i<m;i++) t[i]=b[i];
	ntt(s,1);
	ntt(t,1);
	for (long long i=0;i<sz;i++) t[i]=(2*t[i]-(s[i]*t[i]%mod)*t[i])%mod;
	ntt(t,-1);
	for (long long i=0;i<sz;i++) b[i]=t[i];
}
void inv(long long deg,long long a[],long long b[])
{
	if (deg==1) 
	{
		b[0]=binpow(a[0],mod-2);
		return;
	}
	inv((deg+1)>>1,a,b);
	geti(a,b,deg,(deg+1)>>1);
}
void getsqrt(long long a[],long long b[],long long n,long long m)
{
	for (long long i=0;i<m;i++) c[i]=b[i]*2%mod;
	inv(n,c,d);
	sz=1;cnt=0;
	while(sz<2*n) 
	{
		sz*=2;
		cnt++;
	} 
	rev[0]=0;
	for (long long i=1;i<sz;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
	}
	for (long long i=0;i<sz;i++) s[i]=t[i]=g[i]=0;
	for (long long i=0;i<n;i++) s[i]=a[i];
	for (long long i=0;i<m;i++) t[i]=b[i];
	for (long long i=0;i<n;i++) g[i]=d[i];
	ntt(s,1);
	ntt(t,1);
	ntt(g,1);
	for (long long i=0;i<sz;i++) t[i]=(t[i]*t[i]%mod+s[i])*g[i]%mod;
	ntt(t,-1);
	for (long long i=0;i<sz;i++) b[i]=t[i];
}
void Sqrt(long long deg,long long a[],long long b[])
{
	if (deg==1) 
	{
		b[0]=1;
		return;
	}
	Sqrt((deg+1)>>1,a,b);
	getsqrt(a,b,deg,(deg+1)>>1);
}
int main()
{
	scanf("%lld%lld",&n,&m);
	a[0]=1;
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		a[x]-=4;
	}
	Sqrt(m+1,a,b);
	b[0]++;
	inv(m+1,b,a);
	for (long long i=1;i<=m;i++)
	{
		printf("%lld\n",(a[i]*2%mod+mod)%mod);
	}
	return 0;
}