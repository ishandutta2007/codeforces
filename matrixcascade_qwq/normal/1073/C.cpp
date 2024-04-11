//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
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
char c[maxn];
int L[maxn],U[maxn];
int vis[maxn];int x,y;
int check(int xx)
{
	int nx,ny;
	for(int l=1;l+xx-1<=n;++l)
	{
		
		int r=l+xx-1;//cout<<l<<" "<<n;edl;
		nx=L[l-1]+(L[n]-L[r]);
		ny=U[l-1]+(U[n]-U[r]);
		int gx=x,gy=y;
		gx-=nx;gy-=ny;
		int w=abs(gx)+abs(gy)-xx;
	// 	cout<<xx<<" "<<gx<<" "<<gy;edl;
		if(w<=0&&abs(w)%2==0)return 1;
	}
	return 0;
} 
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		scanf("%s",c+1);
		up(i,1,n)
		{
			L[i]=L[i-1]+(c[i]=='R')-(c[i]=='L');
			U[i]=U[i-1]+(c[i]=='U')-(c[i]=='D');
		}
		rd(x);rd(y);
		int nx=L[n],ny=U[n];
		int ll=0,rr=n,ans=-1;
		while(ll<=rr)
		{
		//	cout<<l<<" "<<r;edl;
			int mid=(ll+rr)>>1;
			if(check(mid))
			{
				ans=mid;rr=mid-1;
			}
			else
			{
				ll=mid+1;
			}
		}
	//	if(ans!=-1)ans++;
		opl(ans);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/