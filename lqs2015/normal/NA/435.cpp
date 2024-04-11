#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<18,mod=998244353;
int w[2][333333],S[333333],T[333333],n,sz,cnt,rev[333333],cur,gg[333333],G[333333],res[333333],jc[333333],injc[333333];
long long c[333333],m;
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
	for (int i=MAXN-1;i>=0;i--) injc[i]=1ll*injc[i+1]*(i+1)%mod;
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
int main()
{
	Init();
	scanf("%d%lld",&n,&m);
	m%=(mod-1);
	for (int i=0;i<=n;i++) scanf("%d",&S[i]);
	sz=1;
	while(sz<2*n+2)
	{
		sz<<=1;
		cnt++;
	}
	for (int i=0;i<=n;i++)
	{
		S[i]=1ll*S[i]*jc[i]%mod;
		T[n-i]=injc[i];
	}
	doit();
	for (int i=0;i<=n;i++) res[i]=1ll*S[n+i]*injc[i]%mod;
	for (int i=0;i<=n;i++) res[i]=1ll*res[i]*binpow(binpow(i+1,mod-2),m)%mod;
	memset(S,0,sizeof(S));memset(T,0,sizeof(T));
	for (int i=0;i<=n;i++)
	{
		if (i&1) S[i]=-1ll*res[i]*jc[i]%mod;
		else S[i]=1ll*res[i]*jc[i]%mod;
		T[n-i]=injc[i];
	}
	doit();
	for (int i=0;i<=n;i++)
	{
		if (i&1) res[i]=-1ll*S[n+i]*injc[i]%mod;
		else res[i]=1ll*S[n+i]*injc[i]%mod;
	}
	for (int i=0;i<=n;i++) printf("%d ",(res[i]+mod)%mod);
	printf("\n");
	return 0;
}