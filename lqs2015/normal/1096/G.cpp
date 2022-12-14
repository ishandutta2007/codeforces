#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int sz,cnt,rev[2222222],ls,psz;
int s[2222222],t[2222222],a[111],n,k,pw[2222222],ipw[2222222],ctt,tmp1,tmp2,w,wn;
long long ans;
inline int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=(long long)res*p%mod;
		p=(long long)p*p%mod;
	}
	return res;
}
inline void ntt(int c[],int flag)
{
	for (int i=0;i<sz;i++)
	{
		if (rev[i]>i) swap(c[i],c[rev[i]]);
	}
	for (int i=2;i<=sz;i<<=1)
	{
		for (int j=0;j<sz;j+=i)
		{
			w=1;
			if (flag==1) wn=pw[i];
			else wn=ipw[i];
			int p=i>>1;
			for (int k=j;k<j+p;k++)
			{
				ls=k+p;
				tmp1=c[k];
				tmp2=(long long)c[ls]*w%mod;
				c[k]=tmp1+tmp2;
				c[ls]=tmp1-tmp2;
				if (c[k]>=mod) c[k]-=mod;
				if (c[ls]<0) c[ls]+=mod;
				w=(long long)w*wn%mod;
			}
		}
	}
	if (flag==-1)
	{
		int inv=binpow(sz,mod-2);
		for (int i=0;i<sz;i++)
		{
			c[i]=(long long)c[i]*inv%mod;
		}
	}
}
struct polynomial
{
	int a[2222222],len;
}res,p;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++) scanf("%d",&a[i]);
	for (int i=1;i<=k;i++) p.a[a[i]]=1;
	p.len=10;
	res.len=1;res.a[0]=1;
	for (int i=0;i<=21;i++)
	{
		pw[1<<i]=binpow(3,(mod-1)/(1<<i));
		ipw[1<<i]=binpow(3,(mod-1)-(mod-1)/(1<<i));
	}
	sz=1;
	while(sz<=9*(n/2)) 
	{
		sz*=2;
		cnt++;
	}
	rev[0]=0;
	for (int i=1;i<sz;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
	}
	ntt(p.a,1);
	for (int i=0;i<sz;i++) p.a[i]=binpow(p.a[i],n>>1);
	ntt(p.a,-1);
	for (int i=0;i<=9*(n/2);i++)
	{
		ans=(ans+(long long)p.a[i]*p.a[i])%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}