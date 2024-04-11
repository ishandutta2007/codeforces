/*
qwq
*/


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
int vis[2020][2020];
int step[2020][2020];
int ans[202020];
const int mod=1e9+7;
int dx[8]={1,2,2,1,-1,-2,-2,-1},dy[8]={2,1,-1,-2,2,1,-1,-2};
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
signed main()
{
	int T=1;
	while(T--)
	{
		rdk; rdn;
		up(i,1,n)
		{
			int x,y;rd(x);rd(y);
			x+=1001,y+=1001;
			vis[x][y]=1;
		}
		queue<pii>q;
		q.push(mkp(1001,1001));
		vis[1001][1001]=1;
		step[1001][1001]=0;
		while(!q.empty())
		{
			pii nw=q.front();q.pop();
			int x=nw.fi,y=nw.se;
		//	cout<<x<<" "<<y<<" "<<vis[x][y];edl;
			ans[step[x][y]]++;
			vis[x][y]=1;
			if(step[x][y]>=450)continue;
			
			up(i,0,7)
			{
				int px=x+dx[i],py=y+dy[i];
				if(vis[px][py]==1)
				{
				//	cout<<x<<" "<<y<<" "<<px<<" "<<py<<" qwq\n";
					continue;
				}
				step[px][py]=step[x][y]+1;
				vis[px][py]=1;
				q.push(mkp(px,py));
			}
		} 
		int as=0;
		if(k<=440)
		{
			up(i,0,k)
			{
				as+=ans[i];
			}
			opl(as);
		}
		else
		{
			up(i,0,440)
			{
				as+=ans[i];
			}
			int ss=as;
//			up(i,441,k)
//			{
//				ans[i]=ans[i-1]+28;
//				ss+=ans[i];
//				ss%=mod;
//			}
		//	up(i,429,441)cout<<ans[i]<<" ";
			int del=ans[440]-ans[439];
	//		cout<<del<<" ";
	//		edl;
		//	cout<<(k-441)*28;edl;
		//	as+=(ans[441]+)
		//	cout<<<<" "<<ans[k]<<'\n';
		//	as+=
			as+=(ans[441]+ans[441]+((k-441)%mod)*del%mod)*((k-440)%mod)%mod*qpow(2)%mod;
			as%=mod;
			cout<<as;
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/