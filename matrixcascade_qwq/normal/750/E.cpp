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
const int maxn=8e5+10;
#define mid ((l+r)>>1)
#define ls ((x<<1))
#define rs ((x<<1)|1)
int a[maxn];
struct node
{
	int f[5][5];
	node()
	{
		memset(f,0x3f,sizeof(f));
	}
	node operator *(const node &x)const
	{
		node ans;
		up(t,0,4)
		{
			up(i,0,4)
			{
				up(j,0,4)
				{
					chkmin(ans.f[i][j],f[i][t]+x.f[t][j]);
				}
			}
		}
		return ans;
	}
}ans[maxn];
node w[11];
void build(int x,int l,int r)
{
	if(l==r)
	{
		ans[x]=w[a[l]];return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	ans[x]=ans[ls]*ans[rs];
}
node ww;
void query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		ww=ww*ans[x];return;
	}
	if(ql<=mid)query(ls,l,mid,ql,qr);
	if(mid<qr)query(rs,mid+1,r,ql,qr);
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;int q;rd(q);
		upn scanf("%1lld",&a[i]);
		up(i,0,9)memset(w[i].f,1,sizeof(w[i].f));
		w[3].f[0][0]=0;w[3].f[1][1]=0;w[3].f[2][2]=0;w[3].f[3][3]=0;w[3].f[4][4]=0;
		w[4].f[0][0]=0;w[4].f[1][1]=0;w[4].f[2][2]=0;w[4].f[3][3]=0;w[4].f[4][4]=0;
		w[5].f[0][0]=0;w[5].f[1][1]=0;w[5].f[2][2]=0;w[5].f[3][3]=0;w[5].f[4][4]=0;
		w[8].f[0][0]=0;w[8].f[1][1]=0;w[8].f[2][2]=0;w[8].f[3][3]=0;w[8].f[4][4]=0;
		w[9].f[0][0]=0;w[9].f[1][1]=0;w[9].f[2][2]=0;w[9].f[3][3]=0;w[9].f[4][4]=0;
		
		w[2].f[0][0]=1;w[2].f[1][1]=0;w[2].f[2][2]=0;w[2].f[3][3]=0;w[2].f[4][4]=0;w[2].f[0][1]=0;
		w[0].f[0][0]=0;w[0].f[1][1]=1;w[0].f[2][2]=0;w[0].f[3][3]=0;w[0].f[4][4]=0;w[0].f[1][2]=0;
		w[1].f[0][0]=0;w[1].f[1][1]=0;w[1].f[2][2]=1;w[1].f[3][3]=0;w[1].f[4][4]=0;w[1].f[2][3]=0;
		w[7].f[0][0]=0;w[7].f[1][1]=0;w[7].f[2][2]=0;w[7].f[3][3]=1;w[7].f[4][4]=0;w[7].f[3][4]=0;
		w[6].f[0][0]=0;w[6].f[1][1]=0;w[6].f[2][2]=0;w[6].f[3][3]=1;w[6].f[4][4]=1;
		node h=w[2];
		h=h*w[0];
		h=h*w[1];
		h=h*w[7];
//		up(i,0,4)
//		{
//			up(j,0,4)
//			{
//				cout<<h.f[i][j]<<" ";
//			}edl;
//		}
		build(1,1,n);
		while(q--)
		{
			memset(ww.f,1,sizeof(ww.f));
			ww.f[0][0]=0;
			int l,r;rd(l);rd(r);
			query(1,1,n,l,r);
			int as=ww.f[0][4];
//			up(i,0,4)
//			{
//				up(j,0,4)
//				{
//					cout<<ww.f[i][j]<<" ";
//				}edl;
//			}
			if(as>1000000)as=-1;
			opd(as);edl;
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