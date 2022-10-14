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
unordered_map<int,int>f1[23],f2[23];
const int maxn=(1<<20)+10;
int dp[maxn],g[maxn],mn[maxn];
int gr[maxn],f[maxn];
string s[23];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		up(i,0,n-1)
		{
			int nw=0,mnn=Min();
			cin>>s[i];
			up(j,0,s[i].size()-1)
			{
				if(s[i][j]=='(')++nw;
				else --nw;
				mnn=min(mnn,nw);
				f1[i][nw]++;
				if(f2[i].find(nw)==f2[i].end())f2[i][nw]=f1[i][nw+1];
			}
			g[i]=nw;mn[i]=mnn;
		}
		int ans=0;
		up(i,0,n-1)gr[1<<i]=g[i];
		up(i,0,n-1)
		{
			up(j,0,(1<<n)-1)
			{
				if(j&(1<<i))
				{
					gr[j]+=gr[j^(1<<i)];
				}
			}
		}
		up(i,0,(1<<n)-1)
		{
		//	cout<<i<<" "<<gr[i];edl;
		}
		f[0]=1;
		up(i,0,(1<<n)-1)
		{
			if(f[i]==0)continue;
			up(j,0,n-1)
			{
				if(i&(1<<j))continue;
				if(gr[i]+mn[j]>=0)
				{
					chkmax(dp[i^(1<<j)],dp[i]+f1[j][-1*(gr[i])]);f[i^(1<<j)]=1;
				}
				else
				{
					chkmax(ans,dp[i]+f2[j][-1*(gr[i]+1)]);
				}
			}
		}
		up(i,0,(1<<n)-1)
		{
	//		cout<<i<<" "<<dp[i];edl;
			chkmax(ans,dp[i]);
		}
//		cout<<dp[10];edl;
		opl(ans);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/