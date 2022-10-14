#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define int long long
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
const int maxn=1e6+10;
int a[maxn];int col[maxn];
int mx[maxn],mn[maxn],sum[maxn];
int cnt[maxn],tnc[maxn];
ll ans=0;
vector<int>v[maxn];
void Add(int x)
{
	fp v[x] pf ++cnt[to];
}
void Del(int x)
{
	fp v[x] pf --cnt[to];
}
int Qry(int x)
{
	int ans=0;
	fp v[x] pf ans+=tnc[to];
	return ans;
}
void solve(int l,int r)
{
	if(l==r)
	{
		ans++;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	mx[mid]=-1e9,mn[mid]=1e9,sum[mid]=0;sum[mid-1]=0;
	up(i,mid+1,r)mx[i]=max(a[i],mx[i-1]),mn[i]=min(a[i],mn[i-1]),sum[i]=sum[i-1]+(mx[i]%mn[i]==0);
//	cout<<sum[r-1];edl;
	int nmx=-1e9,nmn=1e9;
//	int cmx,cmn;
	int pl=mid,pr;
	int pre=ans;
//	memset(cnt,0,sizeof(cnt));memset(tnc,0,sizeof(tnc));
	unordered_map<int,int>m1,m2;
	pu(i,mid,l)
	{
		
		nmx=max(nmx,a[i]);nmn=min(nmn,a[i]);
		if(i==mid)
		{
			while(pl<r&&mx[pl+1]<nmx&&mn[pl+1]>nmn)
			{
				++pl;
			}
		//	--pl;
			pr=pl;
			while(pr<r&&(mx[pr+1]<nmx||mn[pr+1]>nmn))
			{
//				if(l==1&&r==4&&i==2)cout<<mx[pr+1]<<" "<<cnt[4],mc;
				Add(mx[pr+1]);
				++m1[mx[pr+1]];
				++m2[mn[pr+1]];
				++tnc[(mn[pr+1])];
				++pr;
			}
			
		//	--pr;
		}
		else
		{
			while(pl<r&&mx[pl+1]<nmx&&mn[pl+1]>nmn)
			{
				
			//	mc;
				Del(mx[pl+1]);
				--tnc[(mn[pl+1])];
				--m1[mx[pl+1]];--m2[mn[pl+1]];
				++pl;
			}
		//	--pl;
			while(pr<r&&(mx[pr+1]<nmx||mn[pr+1]>nmn))
			{
				Add(mx[pr+1]);
				++tnc[(mn[pr+1])];
				++m1[mx[pr+1]];++m2[mn[pr+1]];
				++pr;
			}
			
		}
		if(nmx%nmn==0)
		{
			
			ans+=(pl-mid);
		}
		ans+=sum[r]-sum[pr];
		if(mx[pr]>=nmx)
		{
//			if(l==1&&r==4&&i==2)cout<<cnt[4],edl;
			ans+=cnt[nmn];
		}
		else
		{
			ans+=Qry(nmx);
		}
	}
	fp m1 pf
	{
		up(i,1,to.se)Del(to.fi);
	}
	fp m2 pf
	{
		tnc[to.fi]-=to.se;
	}
//	cout<<l<<" "<<mid<<" "<<r<<" "<<ans-pre;edl;
}
/*
1
4
2 4 7 14
*/
signed main()
{
	int T=read();
	while(T--)
	{
		rdn;upn rd(a[i]);
		upn
		{
			if(!v[a[i]].size())
			{
				for(int j=1;j*j<=a[i];++j)
				{
					if(a[i]%j==0)
					{
						v[a[i]].ep(j);
						if(a[i]/j!=j)v[a[i]].ep(a[i]/j);
					}
				}
			}
		}
		ans=0;
		solve(1,n);
		opl(ans);edl;
		upn v[a[i]].clear();
	}
}
/*
5
1 2 3 4 5
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/