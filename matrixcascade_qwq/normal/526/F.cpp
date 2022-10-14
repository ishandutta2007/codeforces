#pragma GCC optimize("Ofast", "unroll-loops")
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

#define inf 1000000000ll
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
const int maxn=303030;
int a[maxn],mx[maxn],mn[maxn];ll ans=0;
unordered_map<int,int> w1,w2;
void solve(int l,int r)
{
	if(l==r)
	{
		ans++;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
unordered_map<int,int> w1,w2;
	mx[mid]=Max(),mn[mid]=Min();
	up(i,mid+1,r)mx[i]=max(a[i],mx[i-1]),mn[i]=min(a[i],mn[i-1]);
	int nmx=Max(),nmn=Min();
	int cmx,cmn;
	int pl=mid,pr;
	pu(i,mid,l)
	{
		nmx=max(nmx,a[i]);nmn=min(nmn,a[i]);
		if(i==mid)
		{
			while(pl<r&&mx[pl+1]<nmx&&mn[pl+1]>nmn)
			{
				++pl;
			}
			pr=pl;
			while(pr<r&&(mx[pr+1]<nmx||mn[pr+1]>nmn))
			{
				++w1[mn[pr+1]+pr+1];
				++w2[mx[pr+1]-pr-1];
				++pr;
			}
		}
		else
		{
			while(pl<r&&mx[pl+1]<nmx&&mn[pl+1]>nmn)
			{
				--w1[mn[pl+1]+pl+1];
				--w2[mx[pl+1]-pl-1];
				++pl;
			}

			while(pr<r&&(mx[pr+1]<nmx||mn[pr+1]>nmn))
			{
				++w1[mn[pr+1]+pr+1];
				++w2[mx[pr+1]-pr-1];
				++pr;
			}
		}
		int pos=i+(nmx-nmn);
	//	cout<<i<<" "<<pl<<" "<<pr;edl;
		if(pos>=mid+1&&pos<=pl)
		{
			++ans;
		}
		if(mx[pr]>nmx)
		{
		//	if(w2[nmn-i]!=0)cout<<i,edl;
			ans+=w2[nmn-i];
		}
		else
		{
			ans+=w1[nmx+i];
		}
	}
	nmx=Max();nmn=Min();
	pl=mid+1;
//	opl(pl);edl;
	mx[mid]=mn[mid]=a[mid];
	pu(i,mid-1,l)mx[i]=max(a[i],mx[i+1]),mn[i]=min(a[i],mn[i+1]);
	up(i,mid+1,r)
	{
        int pos=i-mx[i]+mn[i];
        if(pos<=mid&&pos>=l&&mx[pos]<mx[i]&&mn[pos]>mn[i])
        {
            ++ans;
        }
    }
//	mx[]
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn
		{
			int x,y;rd(x);rd(y);
			a[x]=y;
		}
//		edl;
		solve(1,n);
		opl(ans);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/