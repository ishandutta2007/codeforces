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
const int maxn=303030;
int f[maxn][20],a[maxn],lg[maxn];
int nxt[maxn];
int w[maxn];
void pre(int n) 
{
    lg[0]=-1;
    up(i,1,n)lg[i]=lg[i>>1]+1;
    up_(19)
    {
        for(int j=1;j+(1<<(i-1))<=n;j++)
        {
            f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
        }
    }
}
int qry(int l,int r)
{
    int ww=lg[r-l+1];
    int ans=min(f[l][ww],f[r-(1<<ww)+1][ww]);
    return ans;
}
int dp[maxn][20];
int qmax(int l,int r)
{
	int len=lg[r-l+1];
	if(a[dp[l][len]]>a[dp[r-(1<<len)+1][len]])return dp[l][len];
	else return dp[r-(1<<len)+1][len];
}
int sum=0;
void solve(int l,int r)
{
	if(l>r)return;
	if(l==r)
	{
		if(a[l]==1)sum++;return;
	}
	int mid=qmax(l,r);
	//cout<<l<<" "<<r<<" "<<mid<<'\n';
//	if(mid==l)
//	{
//		sum+=(a[mid]==1);
//		solve(mid+1,r);
//		return;
//	}
//	if(mid==r)
//	{
//		sum+=(a[mid]==1);
//		solve(l,mid-1);
//		return;
//	}
	
	int len=a[mid];
	if(mid-l+1<=r-mid+1)
	{
		
		up(i,l,mid)
		{
			int L=i,R=i+len-1;
			if(R>r||R<mid)continue;
			if(qry(L,R)>R)++sum;
		}
		solve(l,mid-1);solve(mid+1,r);
		return;
	}
	up(i,mid,r)
	{
		
		int L=i-len+1,R=i;
		if(L<l||L>mid)continue;
		if(qry(L,R)>R)
		{
			++sum;//,opls(L),opls(R),opls(qry(L,R)),edl;
		}
	}
	solve(l,mid-1);solve(mid+1,r);
	return;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn rd(a[i]);
		upn nxt[i]=w[i]=(n+1);
		pu(i,n,1)
		{
			nxt[i]=w[a[i]];w[a[i]]=i;dp[i][0]=i;
		}
		upn f[i][0]=nxt[i];
	//	upn opl(nxt[i]),edl;
		pre(n);
		up(j,1,19)
		{
			for(int i=1;i+(1<<j)-1<=n;++i)
			{
				if(a[dp[i][j-1]]>a[dp[i+(1<<(j-1))][j-1]])dp[i][j]=dp[i][j-1];
				else dp[i][j]=dp[i+(1<<(j-1))][j-1];
			}
		}
		solve(1,n);
		opl(sum);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/


//v