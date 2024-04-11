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
const int maxn=1e6+10;
int a[maxn];int col[maxn];
int mx[maxn],mn[maxn],sum[maxn];
int cnt[100],tnc[100];
int ans=0;
void solve(int l,int r)
{
	if(l==r)
	{
		ans++;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	mx[mid]=Max(),mn[mid]=Min(),sum[mid]=0;sum[mid-1]=0;
	up(i,mid+1,r)mx[i]=max(a[i],mx[i-1]),mn[i]=min(a[i],mn[i-1]),sum[i]=sum[i-1]+(__builtin_popcountll(mx[i])==__builtin_popcountll(mn[i]));
//	cout<<sum[r-1];edl;
	int nmx=Max(),nmn=Min();
	int cmx,cmn;
	int pl=mid,pr;
	memset(cnt,0,sizeof(cnt));memset(tnc,0,sizeof(tnc));
	pu(i,mid,l)
	{
		nmx=max(nmx,a[i]);nmn=min(nmn,a[i]);
		if(a[i]==nmx)cmx=col[i];
		if(a[i]==nmn)cmn=col[i];
		if(i==mid)
		{
			while(pl<r&&mx[pl+1]<nmx&&mn[pl+1]>nmn)
			{
				++pl;
			}
		//	--pl;
			pr=pl;
			while(pr<r&&(mx[pr+1]<nmx||mn[pr+1]>nmn))
			{
				++cnt[__builtin_popcountll(mx[pr+1])];
				++tnc[__builtin_popcountll(mn[pr+1])];
				++pr;
			}
			
		//	--pr;
		}
		else
		{
			while(pl<r&&mx[pl+1]<nmx&&mn[pl+1]>nmn)
			{
				
			//	mc;	
				--cnt[__builtin_popcountll(mx[pl+1])];
				--tnc[__builtin_popcountll(mn[pl+1])];
				++pl;
			}
		//	--pl;
			while(pr<r&&(mx[pr+1]<nmx||mn[pr+1]>nmn))
			{
				++cnt[__builtin_popcountll(mx[pr+1])];
				++tnc[__builtin_popcountll(mn[pr+1])];
				++pr;
			}
			
		}
		if(cmx==cmn)
		{
			ans+=(pl-mid);assert(pl-mid>=0);
		}
		ans+=sum[r]-sum[pr];
		if(mx[pr]>=nmx)
		{
			if(l==1&&r==5)
			{
		//		mc;
			}
			ans+=cnt[cmn];
		}
		else
		{
			ans+=tnc[cmx];
		}
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;upn rd(a[i]),col[i]=__builtin_popcountll(a[i]);
		solve(1,n);
		opl(ans);edl;
	}
}
/*
5
1 2 3 4 5
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/