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
int w[505][505][5];
int val[505][505][5];
int ds[505][505];
struct node
{
	int x,y,dis;
	bool operator<(const node&b) const
	{
		return dis>b.dis;
	}
	node(int xx=0,int yy=0,int dd=0)
	{
		x=xx;y=yy;dis=dd;
	}
};
void dij()
{
	priority_queue<node>q;
	node nw=node();q.push(nw);
	ds[0][0]=1;
	while(!q.empty())
	{
		nw=q.top();q.pop();
		int x=nw.x,y=nw.y,dis=nw.dis;
		if(x>0&&ds[x-1][y]>dis+val[x][y][1])
		{
			ds[x-1][y]=dis+val[x][y][1],q.push(node(x-1,y,ds[x-1][y]));
		}
		if(x<k&&ds[x+1][y]>dis+val[x][y][2])
		{
			ds[x+1][y]=dis+val[x][y][2],q.push(node(x+1,y,ds[x+1][y]));
		}
		if(y>0&&ds[x][y-1]>dis+val[x][y][3])
		{
			ds[x][y-1]=dis+val[x][y][3],q.push(node(x,y-1,ds[x][y-1]));
		}
		if(y<k&&ds[x][y+1]>dis+val[x][y][4])
		{
			ds[x][y+1]=dis+val[x][y][4],q.push(node(x,y+1,ds[x][y+1]));
		}
	}
}
signed main()
{
	
	int T=read();
	while(T--)
	{
		rdn;rdk;
		up(i,0,k)
		{
			up(j,0,k)
			{
				ds[i][j]=Min();
				up(t,1,4)
				{
					w[i][j][t]=val[i][j][t]=0;
				}
			}
		}
		upn
		{
			int a,b,c,d;rd(a);rd(b);rd(c);rd(d);
			if(b==d)
			{
				int t=min(a,c);
				//opl(t);edl;
				w[t][b-1][4]++;w[t][b][3]++;
			}
			else
			{
				int t=min(b,d);
				w[a-1][t][2]++;
				w[a][t][1]++;
			}
		}
		up(i,0,k)
		{
			up(j,0,k)
			{
				up(t,1,4)
				{
					int opt;
					if(t==1)opt=2;
					if(t==2)opt=1;
					if(t==3)opt=4;
					if(t==4)opt=3;
					val[i][j][t]=w[i][j][t]+w[k-i][k-j][opt];
				}
			}
		}
		dij();
		opl(n-ds[k/2][k/2]);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/