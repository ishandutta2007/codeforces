#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=1e6,MAXN=1<<21;
int jc[2222222],injc[2222222],n,a,b,s[2222222],t[2222222],l,r,pw[2222222],sz,rev[2222222],cnt;
int S[2222222],T[2222222],G[2222222],w[2][2222222],cur,gg[2222222];
long long c[2222222];
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
int C(int n,int k)
{
	if (n<k) return 0;
	return ((long long)jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
void Init()
{
	jc[0]=injc[0]=1;
	for (int i=1;i<=maxn;i++)
	{
		jc[i]=(long long)jc[i-1]*i%mod;
	}
	injc[maxn]=binpow(jc[maxn],mod-2);
	for (int i=maxn-1;i>=0;i--) injc[i]=(long long)injc[i+1]*(i+1)%mod;
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
		if (i==65536) 
		{
			for (int j=0;j<sz;j++) c[j]%=mod;
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
	if (sz<=64)
	{
		for (int i=0;i<sz;i++) G[i]=0;
		for (int i=0;i<sz;i++)
		{
			for (int j=0;j<sz-i;j++)
			{
				G[i+j]=((long long)S[i]*T[j]+G[i+j])%mod;
			}
		}
		for (int i=0;i<sz;i++) S[i]=G[i];
		return;
	}
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
void solve(int n)
{
	if (n==1)
	{
		s[1]=1;
		return;
	}
	if (!n)
	{
		s[0]=1;
		return;
	}
	if (n&1)
	{
		solve(n-1);
		t[0]=(long long)s[0]*(n-1)%mod;
		for (int i=1;i<=n;i++) t[i]=((long long)s[i]*(n-1)+s[i-1])%mod;
		for (int i=1;i<=n;i++) s[i]=t[i];
	}
	else
	{
		solve(n>>1);
		pw[0]=1;
		sz=1;cnt=0;
		while(sz<=n) 
		{
			sz*=2;
			cnt++;
		}
		int c=(n>>1);
		for (int i=1;i<=c;i++) pw[i]=(long long)pw[i-1]*c%mod;
		for (int i=0;i<sz;i++) S[i]=T[i]=0;
		for (int i=0;i<=c;i++) S[i]=(long long)s[i]*jc[i]%mod;
		for (int i=0;i<=c;i++) T[i]=(long long)pw[i]*injc[i]%mod;
		reverse(T,T+c+1);
		doit();
		for (int j=0;j<sz;j++) T[j]=0;
		for (int j=c;j<=n;j++) T[j-c]=(long long)S[j]*injc[j-c]%mod;
		for (int j=0;j<sz;j++) S[j]=s[j];
		doit();
		for (int j=0;j<=n;j++) s[j]=S[j];
	}
}
int main()
{
	cin>>n>>a>>b;
	Init();
	n--;
	if (!n)
	{
		if (!(a+b-2)) cout<<C(a+b-2,a-1)<<endl;
		else cout<<0<<endl;
		return 0;
	}
	solve(n);
	cout<<((long long)s[a+b-2]*C(a+b-2,a-1)%mod+mod)%mod<<endl;
	return 0;
}