#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<20,mod=998244353;
int w[2][1111111],S[1111111],T[1111111],n,m,sz,cnt,rev[1111111],cur,gg[1111111],G[1111111],K,a[333333],b[333333],crt,ans;
long long c[1111111];
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
	S[0]=1;S[2]=1;S[1]=(K-2)%mod;
	ntt(S,0);
	for (int i=0;i<sz;i++) S[i]=binpow(S[i],crt);
	ntt(S,1);
} 
int main()
{
	Init();
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) b[i]=a[i+1];
	b[n]=a[1];
	sz=1;
	while(sz<2*n)
	{
		sz<<=1;
		cnt++;
	}
	for (int i=1;i<=n;i++) 
	{
		if (a[i]==b[i]) continue;
		crt++;
	}
	doit();
	for (int i=crt+1;i<sz;i++) ans=(ans+S[i])%mod;
	ans=1ll*ans*binpow(K,n-crt)%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}