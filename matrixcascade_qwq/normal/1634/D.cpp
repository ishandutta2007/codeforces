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
int vis[10101];
signed main()
{
	int T=read();
	while(T--)
	{
		rdn;
		upn vis[i]=0;
		vector<int>v;
		upn
		{
			v.ep(i);
		}
		while(1)
		{
			if(v.size()==3)
			{
				up(i,0,2)vis[v[i]]=1;
				up(i,1,n)
				{
					if(!vis[i])
					{
						v.ep(i);break;
					}
				}
				upn vis[i]=0;
			}
			else if(v.size()==2)
			{
				cout<<"! "<<v[0]<<" "<<v[1]<<endl;break;
			}
			else if(v.size()==1)
			{
				if(v[0]==1)
				{
					cout<<"! 1 2"<<endl;break;
				}
				else
				{
					cout<<"! 1 "<<v[0]<<endl;break;
				}
			}
			else
			{
				
				int a1=v.back();v.pop_back();
				int a2=v.back();v.pop_back();
				int a3=v.back();v.pop_back();
				int a4=v.back();v.pop_back();
				int a123,a124,a134,a234;
				cout<<"? "<<a1<<" "<<a2<<" "<<a3<<" "<<endl;
				cin>>a123; 
				cout<<"? "<<a1<<" "<<a2<<" "<<a4<<" "<<endl;
				cin>>a124; 
				cout<<"? "<<a1<<" "<<a3<<" "<<a4<<" "<<endl;
				cin>>a134; 
				cout<<"? "<<a2<<" "<<a3<<" "<<a4<<" "<<endl;
				cin>>a234; 
				map<int,int>mp;
				mp[a123]++;mp[a124]++;mp[a134]++;mp[a234]++;
				if(mp.size()==1)
				{
					continue;
				}
				else if(mp.size()==2)
				{
					if(mp[a123]==2)
					{
						int mx=Max(a123,a124,a134,a234);
						if(a123==a124&&a123==mx)
						{
							v.ep(a1);v.ep(a2);
						}
						if(a123==a134&&a123==mx)
						{
							v.ep(a1);v.ep(a3);
						}
						if(a123==a234&&a123==mx)
						{
							v.ep(a2);v.ep(a3);
						}
						if(a134==a124&&a124==mx)
						{
							v.ep(a1);v.ep(a4);
						}
						if(a134==a234&&a134==mx)
						{
							v.ep(a3);v.ep(a4);
						}
						if(a124==a234&&a124==mx)
						{
							v.ep(a2);v.ep(a4);
						}
						continue;
					}
					if(mp[a123]==1)
					{
						v.ep(a4);
					}
					else if(mp[a124]==1)
					{
						v.ep(a3);
					}
					else if(mp[a134]==1)
					{
						v.ep(a2);
					}
					else
					{
						v.ep(a1);
					}
				}
				else if(mp.size()==3)
				{
					if(a123==a124)
					{
						v.ep(a1);v.ep(a2);
					}
					if(a123==a134)
					{
						v.ep(a1);v.ep(a3);
					}
					if(a123==a234)
					{
						v.ep(a2);v.ep(a3);
					}
					if(a134==a124)
					{
						v.ep(a1);v.ep(a4);
					}
					if(a134==a234)
					{
						v.ep(a3);v.ep(a4);
					}
					if(a124==a234)
					{
						v.ep(a2);v.ep(a4);
					}
					
				}
			}
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