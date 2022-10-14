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
int a[1010101];
vector<int>v1[1010101],v2[1010101];
signed main()
{
	int T=read();
	while(T--)
	{
		rdn;rdm;
		upn rd(a[i]);
		int g=0;
		up_(m)g=__gcd(g,read());
		up(i,0,g-1)v1[i].clear(),v2[i].clear();
		upn
		{
			if(a[i]<0)v1[i%g].ep(a[i]);
			else v2[i%g].ep(a[i]);
		}
		int ans1=0;
		up(i,0,g-1)
		{
			sort(v1[i].begin(),v1[i].end());
			int val=0;
			fp v2[i] pf val+=to;
			fp v1[i] pf val-=to;
			int mn=Min();
			fp v2[i] pf chkmin(mn,to);
			fp v1[i] pf chkmin(mn,-to);
			if(v1[i].size()%2==1)
			{
				val-=mn*2;
			}
			ans1+=val;
		}
		up(i,1,g)a[i]*=-1;
		up(i,0,g-1)v1[i].clear(),v2[i].clear();
		upn
		{
			if(a[i]<0)v1[i%g].ep(a[i]);
			else v2[i%g].ep(a[i]);
		}
		int ans2=0;
		up(i,0,g-1)
		{
			sort(v1[i].begin(),v1[i].end());
			int val=0;
			fp v2[i] pf val+=to;
			fp v1[i] pf val-=to;
			int mn=Min();
			fp v2[i] pf chkmin(mn,to);
			fp v1[i] pf chkmin(mn,-to);
			if(v1[i].size()%2==1)
			{
				val-=mn*2;
			}
			ans2+=val;
		}
		opl(max(ans1,ans2));edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/