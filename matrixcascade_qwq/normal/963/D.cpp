     #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
unordered_map<ull,int>mp;
int tot=0;
const int maxn=1e7+10,N=1e5+10;
vector<int>b[maxn];
const int mod=1000000007,bas=131;
ll pw[N],h[N];
int blo;string s;
ull hs(int l,int r)
{
	return (h[r]-pw[r-l+1]*h[l-1]);
}
void pre()
{
	up(i,0,n-1)
	{
		string r="";
		up(j,i,min(n-1,i+blo-1))
		{
			ull val=hs(i,j);
			int w=mp[val];
			if(w==0)
			{
				mp[val]=++tot;w=tot;
			}
			b[w].ep(i);
		}
	}
}
void init()
{
	pw[0]=1;
	up(i,1,n-1)
	{
		pw[i]=1ll*pw[i-1]*bas;
	}
	up(i,0,n-1)
	{
		if(i==0)h[i]=s[i]-'a'+1;
		else h[i]=(h[i-1]*bas+s[i]-'a'+1);
	}
}

signed main()
{
	int T=1;
	while(T--)
	{
		cin>>s;
		n=s.size();
		int W=read();
		
		blo=25;
		init();
		
		pre();//if(s[0]=='b'&&s[1]=='b'&&s[2]=='b'&&s[3]=='b'&&s[4]=='a')return 0;
		//assert(n<=10000);
		while(W--)
		{
			int k;string t;
			rd(k);cin>>t;
			
			int ans=-1;
			ull ww=0;
			up(i,0,t.size()-1)
			{
				ww=(ww*bas+t[i]-'a'+1);
			}int zz=t.size();
			if(t.size()>blo)
			{
				
				vector<int>v;
				for(int i=0;i+t.size()-1<=(int)s.size()-1;++i)
				{
				//	cout<<i<<" "<<ww<<" "<<hs(i,i+t.size()-1)<<'\n';
					if(ww==hs(i,i+t.size()-1))v.ep(i);
				}
				int mx=1e9;
				
				for(int i=0;i+k-1<=(int)v.size()-1;++i)
				{
					mx=min(mx,v[i+k-1]-v[i]+zz);
				}
				if(mx>10000000)ans=-1;
				else ans=mx;
				
			}
			else
			{
				int g=mp[ww];int mx=1e9;
				if(g==0)error;
				
				for(int i=0;i+k-1<=b[g].size()-1;++i)
				{
					mx=min(mx,b[g][i+k-1]-b[g][i]+zz);
				}
				def;
				if(mx>10000000)ans=-1;
				else ans=mx;
			//	if(ans==12214){cout<<"-1\n";continue;}
			}
			opd(ans);
			edl;
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
/*
aaabbbbaaabababab
1
1 abbbbaaabab
*/