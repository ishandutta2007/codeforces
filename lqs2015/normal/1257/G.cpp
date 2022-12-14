#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<20,mod=998244353,Maxn=3e6;
int w[2][1111111],S[1111111],T[1111111],n,m,sz,cnt,rev[1111111],cur,gg[1111111],G[1111111],x,num[3333333],a[222222],crt;
int jc[1111111],injc[1111111],arr[22][1111111],fuck[22],s[1111111],cfuck,ans;
long long c[1111111];
const int maxn=1000;
char buffer[maxn],*SS,*TT;
inline char Get_Char()
{
    if(SS==TT)
    {
        TT=(SS=buffer)+fread(buffer,1,maxn,stdin);
        if(SS==TT) return EOF;
    }
    return *SS++;
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
	for (int i=MAXN-1;i>=0;i--) injc[i]=1ll*injc[i+1]*(i+1)%mod;
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
void solve(int l,int r,int dep)
{
	if (l==r)
	{
		cfuck=a[l];
		for (int i=0;i<=a[l];i++) s[i]=1;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid,dep+1);
	fuck[dep]=cfuck;
	for (int i=0;i<=cfuck;i++) arr[dep][i]=s[i];
	solve(mid+1,r,dep+1);
	cnt=0;sz=1;
	while(sz<cfuck+fuck[dep]+2)
	{
		sz<<=1;
		cnt++;
	}
	for (int i=0;i<=cfuck;i++) S[i]=s[i];
	for (int i=0;i<=fuck[dep];i++) T[i]=arr[dep][i];
	doit();
	for (int i=0;i<sz;i++) s[i]=S[i];
	for (int i=0;i<sz;i++)
	{
		S[i]=T[i]=0;
	}
	cfuck+=fuck[dep];
}
int main()
{
	Init();
	n=read();
	for (int i=1;i<=n;i++) 
	{
		x=read();
		num[x]++;
	}
	for (int i=1;i<=Maxn;i++)
	{
		if (num[i]) a[++crt]=num[i];
	}
	solve(1,crt,0);
	printf("%d\n",(s[n/2]+mod)%mod);
	return 0;
}