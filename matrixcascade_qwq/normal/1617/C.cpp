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
int a[101010];
signed main()
{
	int T=read();
	while(T--)
	{
		rdn;
		upn rd(a[i]);
		sort(a+1,a+n+1);
		vector<int>v;map<int,int>mp;
		int q=0;
		upn
		{
			if(a[i]>n+n)
			{
				++q;
			}
			else
			{
				mp[a[i]]++;
			}
		}
		int nw=n/2;
		set<int>s;
		up(i,1,n)
		{
			if(mp[i]==0)s.insert(i);
		}
		int ans=0;
		int flag=1;
		pu(i,n+n,1)
		{
			if(i>n)
			{
				up(j,1,mp[i])
				{
					if(!s.size())
					{
						flag=0;error;
					}
					int val=(i+1)/2-1;
			//		cout<<i<<" "<<val<<'\n';
					auto x=(s.upper_bound(val));
					if(x==s.begin())
					{
						flag=0;error;
					}
					--x;
				//	cout<<*x<<'\n';
					mp[*x]++;
					++ans;
					s.erase(s.find(*x));
				}
			}
			else
			{
				if(mp[i]>1)
				{
					up(j,1,mp[i]-1)
					{
						if(!s.size())
						{
							flag=0;error;
						}
						int val=(i+1)/2-1;
				//	cout<<i<<" "<<val<<'\n';
						auto x=(s.upper_bound(val));
						if(x==s.begin())
						{
							flag=0;error;
						}
						--x;
					//	cout<<*x<<'\n';
						mp[*x]++;
						++ans;
						s.erase(s.find(*x));
					}
					mp[i]=1;
				}
			}
		}
		def;
		upn
		{
			if(!mp[i]&&q)
			{
				++ans;
				mp[i]=1;
				--q;
			}
		}
		upn
		{
			if(mp[i]!=1)flag=0;
		}
		if(!flag)puts("-1");
		else
		{
			cout<<ans;edl;
		}
		
	}
}
/*
1
3
1 5 4
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/