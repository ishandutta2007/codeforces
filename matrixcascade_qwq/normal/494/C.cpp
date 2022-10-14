//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define double long double
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
const int maxn=101010;
int f[maxn][20],a[maxn],lg[maxn];
void pre(int n) 
{
	up(i,1,n)f[i][0]=a[i];
	lg[0]=-1;
	up(i,1,n)lg[i]=lg[i>>1]+1;
	up_(20)
	{
		for(int j=1;j+(1<<(i-1))<=n;j++)
		{
			f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
		}
	}
}
int qry(int l,int r)
{
	int ww=lg[r-l+1];
	int ans=max(f[l][ww],f[r-(1<<ww)+1][ww]);
	return ans;
}
struct node
{
	int l,r;
	double p;
	int val;
}q[5050];
int cmp(node a,node b)
{
	if(a.l==b.l)return a.r>b.r;
	return a.l<b.l;
}
vector<int>v[5050];
double dp[5050][5050];
void dfs(int x)
{
	fp v[x] pf
	{
		dfs(to);
	}
	dp[x][0]=(1.0-q[x].p);
	fp v[x] pf
	{
		dp[x][0]*=dp[to][q[x].val-q[to].val];
	}
	up(i,1,m)
	{
		double xx,y;xx=y=1.0;
		fp v[x] pf
		{
			xx*=dp[to][min(m,i+(q[x].val-q[to].val)-1)];y*=dp[to][min(m,i+(q[x].val-q[to].val))];
		}
		xx*=q[x].p;
		y*=(1-q[x].p);
		dp[x][i]=xx+y;
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		upn rd(a[i]);
		pre(n);
		up_(m)
		{
			rd(q[i+1].l);rd(q[i+1].r);scanf("%Lf",&q[i+1].p);
			q[i+1].val=qry(q[i+1].l,q[i+1].r);
		}
		q[1].l=1;q[1].r=n;q[1].p=0;q[1].val=qry(1,n);++m;
		sort(q+1,q+m+1,cmp);
		int ww=0;
		up(i,1,m)
		{
			pu(j,i-1,1)
			{
				if(q[j].l<=q[i].l&&q[j].r>=q[i].r)
				{
					v[j].ep(i);++ww;
					break;
				}
			}
		}
	//	cerr<<ww<<'\n';
		dfs(1);
		double ans=0;
		up(i,1,m)
		{
			ans+=(dp[1][i]-dp[1][i-1])*(1.0*(i+q[1].val));
		}
		ans+=dp[1][0]*(1.0*(q[1].val));
		printf("%.10Lf",ans);
		
	}
}
/*
qtewry
qertwy
qetyrw
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/