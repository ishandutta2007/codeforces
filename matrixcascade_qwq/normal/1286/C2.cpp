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
char c[111];
vector<basic_string<int>>v[111],g[111];
vector<basic_string<int>>h[111];
int b[200];
basic_string<int> del(basic_string<int>a,basic_string<int>b )
{
	basic_string<int> c;
	up(i,1,29)c.pb(0);
	up(i,0,25)c[i]=a[i]-b[i];
	return c;
}
basic_string<int> add(basic_string<int>a,basic_string<int>b )
{
	basic_string<int> c;
	up(i,1,29)c.pb(0);
	up(i,0,25)c[i]=a[i]+b[i];
	return c;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;map<basic_string<int>,int>mp;
		if(n==2)
		{
			cout<<"? 1 1"<<endl;
			string s;cin>>s;
			cout<<"? 2 2"<<endl;
			string t;cin>>t;
			cout<<"! "<<s<<t<<endl;
			return 0;
		}
		m=(n+1)/2;
		cout<<"? 1 "<<m<<endl;
		string y;
		up(i,1,m*(m+1)/2)
		{
			basic_string<int>nw;
			up(j,1,29)nw.pb(0);
			string w;cin>>w;y=w;
			up(j,0,w.size()-1)nw[w[j]-'a']++;
			mp[nw]++;
		}
		if(n==1)
		{
			cout<<"! "<<y[0]<<endl;return 0;
		}
		cout<<"? 2 "<<m<<endl;
		up(i,1,m*(m-1)/2)
		{
			basic_string<int>nw;
			up(j,1,29)nw.pb(0);
			string w;cin>>w;
			up(j,0,w.size()-1)nw[w[j]-'a']++;
			mp[nw]--;
		}
		fp mp pf
		{
			basic_string<int> qq=to.fi;
			if(to.se==0)continue;
			int val=0;
			up(i,0,25)val+=qq[i];
			v[val].ep(qq);
		}
		basic_string<int> qq;
		up(j,1,29)qq.pb(0);
		v[0].ep(qq);
		up(i,1,m)
		{
			basic_string<int> cur=del(v[i][0],v[i-1][0]);
			up(j,0,25)if(cur[j]==1)c[i]=j+'a';
		}
		
		cout<<"? 1 "<<n<<endl;
		up(i,1,n*(n+1)/2)
		{
			basic_string<int>nw;
			up(j,1,29)nw.pb(0);
			string w;cin>>w;
			up(j,0,w.size()-1)nw[w[j]-'a']++;
			h[w.size()].ep(nw);
		}
		
		pu(i,n,m+1)
		{
			basic_string<int> qq;
			up(j,1,29)qq.pb(0);
			fp h[i-1] pf
			{
				qq=add(qq,to);
			//	cout<<to[1];edl;
			}int ww=0;
			
			pu(j,n,i)
			{
				ww++;
		//		if(i==n)cout<<j<<" "<<c[n-j+1],edl;
				if(j!=i)qq[c[j]-'a']-=ww;
				qq[c[n-j+1]-'a']-=ww;
			}
			if(i==n)
			{
			//	up(j,0,25)cout<<qq[j]<<" ";edl;
			}
		//	if(i==n)cout<<ww,edl;
			up(j,0,25)
			{
				if(qq[j]%(ww+1)!=0)
				{
				//	if(i==n)cout<<j,edl;
					c[i]=j+'a';
					break;
				}
			}
		}
		cout<<"! ";
		up(i,1,n)cout<<c[i];
		cout<<endl;
	}
}
/*
4
a aa a
a
a a b c aa ab bc aab abc aabc
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/