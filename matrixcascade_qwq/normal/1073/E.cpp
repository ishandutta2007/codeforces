//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
#define pb push_back
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}

#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
const int mod=998244353;
int a[22];
const int N=(1<<10)+10;
pii dp[22][N];
int qpow(int a,int b=mod-2)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
pii dfs(int pos,int msk,int zero,int lim)
{
//	if(__builtin_popcount(msk)<=k)mc;
//cout<<pos;edl;
//cout<<dp[pos][msk].fi;edl;
//cout<<pos;edl;
	if(!pos)
	{
	//	if(__builtin_popcount(msk)>=k)mc;
		return mkp(__builtin_popcount(msk)<=k,0);
	}
	if(!lim&&!zero&&~dp[pos][msk].fi)return dp[pos][msk];
	int tp=lim?a[pos]:9;
	pii w;w=mkp(0,0);
	up(i,0,tp)
	{
		pii to=dfs(pos-1,msk|((zero&&i==0)?0:(1<<i)),zero&(i==0),lim&(i==tp));
		w.fi+=to.fi;
		w.se+=to.se+to.fi*qpow(10,pos-1)*i%mod;
	//	cout<<pos<<" "<<to.fi<<" "<<i;edl;
	//	cout<<w.se;edl;
//	cout<<w.fi;edl;
		w.se%=mod;w.fi%=mod;
	}
	if(!zero&&!lim)dp[pos][msk]=w;
	return w;
}
inline int sum(int x)
{
 //   memset(f,-1,sizeof(f));
    a[0]=0;//cout<<x<<" ";
    while(x)a[++a[0]]=x%10,x/=10; 
  //  cout<<a[0]<<" qwq";edl;
  //  reverse(a+1,a+1+a[0]);
    pii w=dfs(a[0],0,1,1);
    return w.se;
}
signed main()
{
	int T=1;
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		int l,r;rd(l);rd(r);rdk;
		int f1=sum(r);//mc;
		int f2=sum(l-1);
	//	cout<<f1<<" "<<f2;edl;
		//cout<<sum(l-1);edl;
		opl((f1-f2+mod)%mod);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/