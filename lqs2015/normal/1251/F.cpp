#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<20,mod=998244353;
int w[2][1111111],S[1111111],T[1111111],n,m,k,sz,cnt,rev[1111111],cur,gg[1111111],G[1111111],jc[1111111],injc[1111111];
long long c[1111111];
int a[333333],b[333333],Q[333333],q,ans[333333],x,y,num[333333],aa[1111111],bb[1111111];
const int maxn=1000;
char buffer[maxn],*s,*t;
inline char Get_Char()
{
    if(s==t)
    {
        t=(s=buffer)+fread(buffer,1,maxn,stdin);
        if(s==t) return EOF;
    }
    return *s++;
}
int read()
{
    char c;
    int re=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char());
    while(c>='0'&&c<='9')
           re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    return re;
}
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=(long long)res*p%mod;
		p=(long long)p*p%mod;
	}
	return res;
}
void Init()
{
	w[0][0]=1;cur=binpow(3,(mod-1)/MAXN);
	for (int i=1;i<=MAXN;i++) w[0][i]=(long long)w[0][i-1]*cur%mod;
	w[1][0]=1;cur=binpow(3,mod-1-(mod-1)/MAXN);
	for (int i=1;i<=MAXN;i++) w[1][i]=(long long)w[1][i-1]*cur%mod;
	jc[0]=1;
	for (int i=1;i<=MAXN;i++) jc[i]=1ll*jc[i-1]*i%mod;
	injc[MAXN]=binpow(jc[MAXN],mod-2);
	for (int i=MAXN-1;i>=0;i--)
	{
		injc[i]=1ll*injc[i+1]*(i+1)%mod;
	}
}
int C(int n,int k)
{
	if (n<0 || k<0 || n<k) return 0;
	return (1ll*jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
void ntt(int d[],int flag)
{
	for (int i=0;i<sz;i++) c[i]=(long long)d[i];
	for (int i=0;i<sz;i++)
	{
		if (rev[i]>i) swap(c[i],c[rev[i]]);
	}
	for (int i=2;i<=sz;i<<=1)
	{
		int p=i>>1,fu=MAXN/i;
		for (int j=0;j<p;j++)
		{
			gg[j]=w[flag][j*fu];
		}
		for (int j=0;j<sz;j+=i)
		{
			for (int k=j;k<j+p;k++)
			{
				long long tmp1=c[k];
				long long tmp2=c[k+p]%mod*gg[k-j];
				c[k]=tmp1+tmp2;
				c[k+p]=tmp1-tmp2;
			}
		}
	}
	for (int j=0;j<sz;j++) c[j]%=mod;
	if (flag)
	{
		int wn=binpow(sz,mod-2);
		for (int i=0;i<sz;i++)
		{
			c[i]=c[i]*wn%mod;
		}
	}
	for (int i=0;i<sz;i++) d[i]=c[i];
}
void doit()
{
	rev[0]=0;
	for (int i=1;i<sz;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
	}
	ntt(S,0);
	ntt(T,0);
	for (int i=0;i<sz;i++) S[i]=(long long)S[i]*T[i]%mod;
	ntt(S,1);
}
void doit2()
{
	rev[0]=0;
	for (int i=1;i<sz;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
	}
	ntt(S,0);
	for (int i=0;i<sz;i++) S[i]=(long long)S[i]*S[i]%mod;
	ntt(S,1);
}
int main()
{
	Init();
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=k;i++) b[i]=read();
	q=read();
	for (int i=1;i<=q;i++) Q[i]=read();
	for (int i=1;i<=n;i++) num[a[i]]++;
	sz=1;cnt=0;
	while(sz<=2*n) 
	{
		sz<<=1;
		cnt++;
	}
	for (int i=0;i<=n;i++) 
	{
		S[i]=injc[i];
	}
	doit2();
	for (int i=0;i<=n;i++) aa[i]=S[i];
	for (int i=1;i<=k;i++)
	{
		x=y=0;
		for (int j=1;j<b[i];j++)
		{
			if (num[j]>=2) y++;
			else if (num[j]) x++;
		}
		sz=1;cnt=0;
		while(sz<=2*y) 
		{
			sz<<=1;
			cnt++;
		}
		for (int j=0;j<sz;j++) S[j]=0;
		for (int j=0;j<=y;j++) S[j]=C(y,j);
		doit2();
		memset(T,0,sizeof(T));
		int psz=sz;
		sz=1;cnt=0;
		while(sz<=2*n) 
		{
			sz<<=1;
			cnt++;
		}
		for (int j=0;j<=x;j++)
		{
			T[j]=1ll*aa[j]*jc[x]%mod*injc[x-j]%mod;
		}
		for (int j=psz;j<sz;j++) S[j]=0;
		doit();
		for (int j=1;j<=q;j++)
		{
			if (Q[j]/2>b[i]) ans[j]=(S[Q[j]/2-b[i]-1]+ans[j])%mod;
		}
	}
	for (int i=1;i<=q;i++) printf("%d\n",(ans[i]+mod)%mod);
	return 0;
}