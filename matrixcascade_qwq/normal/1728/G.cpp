//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define int long long
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
#define edge1 int head[maxn],to[maxn<<1],nxt[maxn<<1],tot;\
void add(int a,int b)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;\
}
#define edge2 int head[maxn],to[maxn<<1],nxt[maxn<<1],tot,w[maxn<<1];\
void add(int a,int b,int c)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;w[tot]=c;\
}
#define Mod998 const int mod=998244353;\
int qpow(int a,int b=mod-2)\
{\
	int ans=1;\
	while(b)\
	{\
		if(b&1)ans=1ll*ans*a%mod;\
		a=1ll*a*a%mod;\
		b>>=1;\
	}\
	return ans;\
}\
void Add(int &a,int b)\
{\
	a+=b;if(a>=mod)a-=mod;\
}\
void Sub(int &a,int b)\
{\
	a-=b;if(a<0)a+=mod;\
}\
int Mul(int a,int b)\
{\
	return 1ll*a*b%mod;\
}\
int Frac(int a,int b)\
{\
	return 1ll*a*qpow(b)%mod;\
}

#define Mod1e9 const int mod=1e9+7;\
int qpow(int a,int b=mod-2)\
{\
	int ans=1;\
	while(b)\
	{\
		if(b&1)ans=1ll*ans*a%mod;\
		a=1ll*a*a%mod;\
		b>>=1;\
	}\
	return ans;\
}\
void Add(int &a,int b)\
{\
	a+=b;if(a>=mod)a-=mod;\
}\
void Sub(int &a,int b)\
{\
	a-=b;if(a<0)a+=mod;\
}\
int Mul(int a,int b)\
{\
	return 1ll*a*b%mod;\
}\
int Frac(int a,int b)\
{\
	return 1ll*a*qpow(b)%mod;\
}

#define DSU int fa[maxn];\
int find(int x)\
{\
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);\
}\
void merge(int x,int y)\
{\
    int fx=find(x),fy=find(y);\
    if(fx==fy)return;\
    fa[fx]=fy;\
}\
void S(int x)\
{\
    up(i,1,x)fa[i]=i;\
}
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
void print(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
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
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
/*
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
void pushup(int x)
{
	//do sth
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		//do sth
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return;
	}
	if(ql<=mid)update(ls,l,mid,ql,qr);
	if(mid<qr)update(rs,mid+1,r,ql,qr);
	pushup(x);
}
void query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return;
	}
	if(ql<=mid)
	{
		query(ls,l,mid,ql,qr);
	}
	if(mid<qr)
	{
		query(rs,mid+1,r,ql,qr);
	}
	return;
}
*/
Mod998;
int d;
const int maxn=5e5+10;
int l[maxn],p[maxn],b[maxn];
const int N=(1<<18)+10;
int f[N],ff[N];
int gg[22][22],gg1[22],gg2[22];
int mk[22][22],sm[22][22];
int sm1[22],sm2[22];
signed main()
{
	int T=1;
	while(T--)
	{
		rd(d);rdn;rdm;
		upn rd(l[i]),++b[l[i]];
		up(i,0,m-1)rd(p[i]);
		sort(p,p+m);
		up(i,0,m-1)
		{
			gg1[i]=1;gg2[i]=1;
			up(j,1,n)
			{
				if(l[j]<=p[i])
				{
					gg1[i]*=(p[i]-l[j]);gg1[i]%=mod;
				}
				if(l[j]>=p[i])
				{
					gg2[i]*=(l[j]-p[i]);gg2[i]%=mod;
				}
			}
		}
		up(i,0,m-1)
		{
			up(j,i+1,m-1)
			{
				gg[i][j]=1;
				up(t,1,n)
				{
					if(l[t]>=p[i]&&l[t]<=p[j])
					{
						gg[i][j]*=min(l[t]-p[i],p[j]-l[t]);gg[i][j]%=mod;
					}
				}
			}
		}
		f[0]=qpow(d,n);
		up(i,1,(1<<m)-1)
		{
			vector<int>id;
			up(j,0,m-1)if(i&(1<<j))id.ep(j);
			f[i]=1;
			f[i]*=gg1[id[0]];
			f[i]*=gg2[id[id.size()-1]];
//			cout<<f[i]<<" qwq\n";
			f[i]%=mod;
			up(j,0,(int)id.size()-2)
			{
				f[i]*=gg[id[j]][id[j+1]];f[i]%=mod;
			}
			int ct=__builtin_popcount(i);
			
			if(ct&1)ff[i]=mod-f[i];
			else ff[i]=f[i];
		}
		int qq=0;
		up(i,0,m-1)
		{
			up(j,i+1,m-1)
			{
				up(msk,0,(1<<m)-1)
				{
					if((msk&(1<<i))==0)continue;
					if((msk&(1<<j))==0)continue;
					int fl=1;
					up(t,i+1,j-1)
					{
//						++qq;
						if(msk&(1<<t))
						{
							fl=0;break;
						}
					}
//					cout<<msk<<;edl;
					if(fl)sm[i][j]+=ff[msk];
					sm[i][j]%=mod;
					
				}
			}
		}
//		cout<<sm[0][1];mc;
		up(i,0,m-1)
		{
			up(msk,0,(1<<m)-1)
			{
				if((msk&(1<<i))==0)continue;
				int fl=1;
				up(t,i+1,m-1)
				{
					if(msk&(1<<t))
					{
						fl=0;break;
					}
				}
				if(fl)Add(sm1[i],ff[msk]);
			}
			up(msk,0,(1<<m)-1)
			{
				if((msk&(1<<i))==0)continue;
				int fl=1;
				up(t,0,i-1)
				{
					if(msk&(1<<t))
					{
						fl=0;break;
					}
				}
				if(fl)Add(sm2[i],ff[msk]);
//				if(i==1)cerr<<msk<<" "<<sm2[i]<<" sb\n";
			}
//			cout<<i<<" qwq "<<sm1[i]<<" ";
		}
//		cout<<sm2[1];mc;
		int q;rd(q);
		while(q--)
		{
			int x;rd(x);
			int as=0;
			up(i,0,m-1)
			{
				up(j,i+1,m-1)
				{
//					cout<<p[i]<<" "<<x<<" "<<p[j],edl;
					if(p[i]<=x&&x<=p[j])
					{
						int ww=min(x-p[i],p[j]-x);
//						cout<<ww;edl;mc;
//						cout<<i<<" "<<j<<" "<<sm[i][j],edl;
						int qw=sm[i][j];Add(as,qw*ww%mod);
					}
				}
			}
			up(i,0,m-1)
			{
				if(p[i]<=x)
				{
					int ww=x-p[i];
					int qw=sm1[i];
//					cout<<ww;edl;
					
					Add(as,qw*ww%mod);
				}
				if(p[i]>=x)
				{
					int ww=p[i]-x;
					int qw=sm2[i];
//					cout<<i<<" "<<qw,edl;
					Add(as,qw*ww%mod);
				}
			}
			as=mod-as;
			as=qpow(d+1,n+1)-as;as+=mod;as%=mod;
			opl(as);edl;
		}
	}
}
/*
6 1 2
4
2 5
1
3

*/

/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/