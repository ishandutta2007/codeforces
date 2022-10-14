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
const int maxn=202020;
int a[maxn],b[maxn];
vector<int>v[maxn];
int siz[maxn],siz1[maxn];
int ans1[maxn],mx[maxn],cmx[maxn],f[maxn];
int ans2[maxn],ans3[maxn];
int nn;
void dfs(int x,int fa)
{
	siz[x]=1;siz1[x]=b[x];nn+=b[x];
	f[x]=fa;
	fp v[x] pf
	{
		if(to==fa)continue;
		dfs(to,x);
		siz[x]+=siz[to];siz1[x]+=siz1[to];
	}
}
void dfs2(int x,int fa)
{
	fp v[x] pf
	{
		if(to==fa)continue;
		dfs2(to,x);
		if(siz1[to]==siz[to])ans1[x]+=siz1[to];
		else
		{
			if(b[to]==1)
			{
				if(ans1[to]+mx[to]+1>mx[x])mx[x]=max(mx[x],(ans1[to]+mx[to]+1));
				else cmx[x]=max(cmx[x],ans1[to]+mx[to]+1);
			}
		}
	}
}
void dfs3(int x,int fa)
{
	if(fa)
	{
		int val=ans1[x]+mx[x]+1;
		int vl;
		if(val==mx[fa])vl=cmx[fa]+1;
		else vl=mx[fa]+1;
		int vl2;
		if(siz1[x]==siz[x])vl2=ans1[fa]-siz1[x];
		else vl2=ans1[fa];
		int faa=f[fa];
		ans2[x]=vl2*(b[fa]==1);
		if(b[fa]==1)
		{
			if(nn-siz1[fa]==n-siz[fa])
			{
				ans2[x]+=n-siz[fa];
			}
			else
			{
				vl=max(vl,ans2[fa]+ans3[fa]+1);
			}
		}
		ans3[x]=vl;
		if(b[fa]==0)ans3[x]=0,ans2[x]=0;
	}
	fp v[x] pf
	{
		if(to==fa)continue;
		dfs3(to,x);
		
	}
}
int check(int x)
{
	nn=0;
	upn b[i]=(a[i]>=x);
//	upn cout<<b[i]<<" ";edl;
	dfs(1,0);
	dfs2(1,0);
	dfs3(1,0);
	int mxx=0;
	upn
	{
		if(b[i]==1)
		{
			int w=ans2[i]+ans1[i]+max(mx[i],ans3[i]);
	//		cout<<i<<" "<<mx[i]<<" "<<ans1[i]<<" "<<ans2[i]<<" "<<ans3[i];edl;
			chkmax(mxx,w+1);
		}
	}
	upn b[i]=0,ans1[i]=ans2[i]=ans3[i]=mx[i]=siz[i]=cmx[i]=siz1[i]=0;
//	cout<<mxx;edl;
	return mxx>=k;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdk;
		upn rd(a[i]);
		up_(n-1)
		{
			int x,y;rd(x);rd(y);v[x].ep(y);v[y].ep(x);
		}
		int l=0,r=1000000;
		int ans=-1,mid;
	//	cout<<check(5);edl;
//		cout<<check(480113);edl;
	//	return 0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		
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
/*
10 3
703660 186846 317819 628672 74457 58472 247014 480113 252764 860936
10 6
7 4
10 9
9 5
6 3
6 2
7 1
10 7
10 8
*/