#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int maxn=(1ll<<23)+10;
const int mod=998244353;
string s[24];
int dp[27];
int ff[27][27];
int f[maxn],h[maxn];
int f1[maxn],f2[maxn];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		up(i,0,n-1) cin>>s[i];
		up(i,0,n-1)
		{
			up(j,0,s[i].size()-1)
			{
				ff[s[i][j]-'a'][i]++;
			}
		}
//		cout<<"qwq "<<dp[3][0]<<" "<<ff[0][0];edl;
		up(i,0,(1<<n)-1)
		{
			up(t,0,26)
			{
				dp[t]=1e9;
				up(j,0,n-1)
				{
					if(i&(1<<j))
					{
						chkmin(dp[t],ff[t][j]);
				//		cout<<i<<" "<<j<<" "<<t<<" "<<ff[t][j];edl;
					}
				}
			}
			f[i]=1;
			up(j,0,26)f[i]=1ll*f[i]*(dp[j]+1)%mod;
	 //		cout<<f[i];edl;
			if(__builtin_popcountll(i)%2==0)
			{
				f1[i]=f[i];
			}
			else f2[i]=f[i];
			f1[0]=f2[0]=0;
		}
		up(i,0,n-1)h[1<<i]=i+1;
		up(i,0,n-1)
		{
			up(j,0,(1<<n)-1)
			{
				if(j&(1<<i))
				{
					h[j]+=h[j^(1<<i)];
					(f1[j]+=f1[j^(1<<i)])%=mod;
					(f2[j]+=f2[j^(1<<i)])%=mod;
					
				}
			}
		}
		ll qw=0;
		up(i,0,(1<<n)-1)
		{
			ll w;
		//	if(__builtin_popcountll(i)%2==0)
		//	{
		//		w=(f1[i]-f2[i]+mod)%mod;
		//	}
		//	else
		//	{
				w=(f2[i]-f1[i]+mod)%mod;
		//	}
			if(i==0)w=0;
			
	//		cout<<i<<" "<<w<<" "<<f1[i]<<" "<<f2[i]<<" "<<h[i];edl;
		//	cout<<h[i];edl;
			w*=h[i];w*=__builtin_popcountll(i);//cout<<w;edl;
		//	cout<<w;edl;
			qw^=(w);//
		}
		opl(qw);
		
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/