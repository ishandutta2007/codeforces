#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<19, mod=998244353;
int w[2][555555],S[555555],T[555555],n,m,sz,cnt,rev[555555],cur,gg[555555],G[555555];
int a[555555], b[555555], pre[555555], suf[555555], x, ans[555555], res;
long long c[555555];
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
	ntt(S,0);
	ntt(T,0);
	for (int i=0;i<sz;i++) S[i]=(long long)S[i]*T[i]%mod;
	ntt(S,1);
} 
void solve(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	sz = 1; cnt = 0;
	while(sz < mid - l + r - mid + 4)
	{
		sz <<= 1;
		cnt++;
	}
	for (int i = 0; i < sz; i++)
	{
		if (i + l <= mid) S[i] = pre[i + l];
		else S[i] = 0;
		if (i + mid + 1 <= r) T[i] = suf[i + mid + 1];
		else T[i] = 0;
	}
	doit();
	for (int i = 0; i < sz; i++)
	{
		if (S[i])
		{
			if ((i + l + mid + 1) % 2 == 0) ans[(i + l + mid + 1) >> 1] = (ans[(i + l + mid + 1) >> 1] + S[i]) % mod; 
		}
	}
}
int main()
{
	Init();
	n=read(); m=read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++)
	{
		x = read();
		b[x + n] = 1;
	} 
	pre[0] = 1;
	for (int i = 1; i <= 3 * n + 1; i++) 
	{
		if (b[i]) pre[i] = (pre[i - 1] + pre[i - 1]) % mod;
		else pre[i] = pre[i - 1];
	}
	suf[3 * n + 1] = 1;
	for (int i = 3 * n; i >= 0; i--)
	{
		if (b[i]) suf[i] = (suf[i + 1] + suf[i + 1]) % mod;
		else suf[i] = suf[i + 1];
	}
	solve(0, 3 * n + 1);
	for (int i = 1; i <= n; i++) res = (1ll * ans[i + n] * a[i] + res) % mod;
	for (int i = 1; i <= n; i++) res = (-1ll * min(n + i, 2 * n + 1 - i) * a[i] + res) % mod;
	res = 1ll * res * binpow(binpow(2, m) - 1, mod - 2) % mod;
	printf("%d\n", (res + mod) % mod);
	return 0;
}