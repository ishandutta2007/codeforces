//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int __int128
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
void wt(int x)
{
	if(x>=10)wt(x/10);
	putchar(x%10+'0');
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
const int m1=1e10;
int sum2(int x)
{
	return x*(x+1)*(2*x+1)/6;
}
int sum1(int x)
{
	return x*(x+1)/2;
}
int f(int x,int y)
{
	return 2*sum2(x)-4*sum1(x)+y*x;
}
int g(int x,int y)
{
	return 2*sum2(x)+y*x;
}
int solve(int x,int y)
{
	if(x==y)
	{
		return (x*x+1)*(x*x)/2;
	}
	if(x<y)
	{
		int ans=(x*x+1)*(x*x)/2;
	//	wt(f(y,x+3));edl;wt(sum2(2));edl;
		ans+=x*(f(y,x+3)-f(x,x+3))/2; 
		return ans;
	}
	else
	{
		int ans=(y*y+1)*(y*y)/2;
		ans+=y*(g(x,1-y)-g(y,1-y))/2;
		return ans;
	}
}

signed main()
{
//	wt(solve(2,1));
//	edl;
//	up(i,1,6)
//	{
//		up(j,1,6)
//		{
//			wt(solve(i,j));cout<<" ";
//		}edl;
//	}
	int T=read();
	while(T--)
	{
		int x1,x2,y1,y2;
		rd(x1);rd(y1);rd(x2);rd(y2);
		int ans=solve(x2,y2)+solve(x1-1,y1-1)-solve(x1-1,y2)-solve(x2,y1-1);
		if(ans>=m1)
		{
			ans%=m1;
			string s=to_string((ll)ans);while(s.size()<10)s='0'+s;
			cout<<"..."<<s;edl;continue;
		}
		wt(ans);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/