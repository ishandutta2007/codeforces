//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
bitset<1001>b[1010],f[1010],fb[1010];
int vis[1010];

bool operator <(bitset<1001>a,bitset<1001>b)
{
	return a.count()<b.count();
}
signed main()
{
	int T=1;
	while(T--)
	{
		int w=0;
		rdn;
		if(n==2)
		{
			cout<<"1 2";return 0;
		}
		upn
		{
			b[i].reset();
			int x;rd(x);w+=x;
			up(j,1,x)
			{
				int t;rd(t);b[i][t]=1;
			}
		}
	//	upn cout<<b[i].size();edl;
		if(w==n*n)
		{
			up(i,2,n)
			{
				opls(i);opls(1ll);edl;
			}
			return 0;
		}
		int nl=0;
		vector<pii>v;
		upn
		{
			up(j,i,n)
			{
				bitset<1001>g=(b[i]&b[j]);
			//	cout<<g.size();edl;
				if(g.count()!=2)continue;
				
				int x=g._Find_first();
				int y=g._Find_next(x);
				vis[x]=1;vis[y]=1;
			//	cout<<x<<" "<<y;edl;
				f[x][y]=f[y][x]=1;
				v.ep(mkp(x,y));
			//	g[x][y]=g[]
			}
		}
		upn
		{
			if(vis[i])nl++,f[i][i]=1;
		}
		if(nl==2)
		{
			int g1=0,g2=0;
			int nw=1;
			upn
			{
				if(vis[i])
				{
					if(g1)g2=i;
					else g1=i;
				}
			}
			unordered_map<bitset<1001>,vector<int>>mmp;
			upn
			{
				if(b[i].count()==n)continue;
				mmp[b[i]].ep(i);
			}
			int gw=0;
		//	cout<<g1<<" "<<g2;edl;
			vector<int>v1,v2;
			fp mmp pf
			{
				if(gw==1)
				{
					up(i,1,n)
					{
						if(i==g1||i==g2)continue;
						if(to.fi[i]==1)
						{
							v2.ep(i);
						}
					}
					break;
				}
				up(i,1,n)
				{
					if(i==g1||i==g2)continue;
					if(to.fi[i]==1)
					{
						v1.ep(i);
					}
				}gw++;
			}
			fp v1 pf v.ep(mkp(to,g1));
			fp v2 pf v.ep(mkp(to,g2));
			sort(v.begin(),v.end());
			v.erase(unique(v.begin(),v.end()),v.end());
	//		cout<<v1.size();edl;cout<<v2.size();edl;
			fp v pf
			{
				cout<<to.fi<<" "<<to.se;edl;
			}
		}
		else
		{
			upn
			{
				if(vis[i]==0)
				{
					up(j,1,n)fb[i][j]=1;
					up(j,1,n)
					{
						if(b[j][i]==1&&b[j].count()<fb[i].count())fb[i]=b[j];
					}
//					up(j,1,n)if(fb[i][j])cout<<j<<" ";
				}
			}
			upn
			{
				bitset<1001>bb;
				if(vis[i]==0)
				{
					
				//	edl;
//					if(fb[i]==b[i])assert(0);
					bb=fb[i];
			//		cout<<i;edl;
			//		up(j,1,n)if(bb[j])cout<<j<<" ";edl;
					up(j,1,n)
					{
						if(vis[j]==0)bb[j]=0;
					}
					up(j,1,n)
					{
						if(vis[j]==1&&bb==f[j])
						{
							v.ep(mkp(i,j));error;
						}
					//	assert(0);
						def;
					}
				}
			}
			sort(v.begin(),v.end());
			v.erase(unique(v.begin(),v.end()),v.end());
			fp v pf
			{
				cout<<to.fi<<" "<<to.se;edl;
			}
		}
	}
}
/*
5
3 5 4 3
3 3 2 1
5 2 1 3 5 4
4 3 2 5 4
4 3 1 4 2

2 3
3 4
1 2
5 4
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/