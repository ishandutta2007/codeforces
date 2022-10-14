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
string s;
int f;
void query(int l1,int r1,int l2,int r2)
{
	cout<<"? ";
	cout<<r1-l1+1<<" "<<r2-l2+1<<'\n';
	up(i,l1,r1)cout<<i<<" ";edl;
	up(i,l2,r2)cout<<i<<" ";cout<<endl;
	cin>>s;
	if(s=="SECOND")f=2;
	else if(s=="FIRST")f=1;
	else f=0;
}
signed main()
{
	srand(time(0));
	int T=read();
	while(T--)
	{
		rdn;rdk;
		
		int qq=0;
		up(i,1,25)
		{
			int pos=rand()%(n-1)+1+1;
			query(1,1,pos,pos);
			if(f==2)
			{
				qq=1;
				cout<<"! "<<1<<endl;break;
			}
		}
		if(qq)continue;
	//	cout<<"! 1"<<endl;continue;
		int p=1,q=1,x=2,y=2;
		while(1)
		{
			y=min(y,n);
			query(1,y-x+1,x,y);
			if(f==1)
			{
			//	assert(0);
				break;
			}
			else
			{
				assert(y!=n);
				q*=2;y=q*2;
				x=q+1;
			}
		}
		int l=x,r=y;
		int ans=0;
		while(l<=r)
		{
			if(l==r)
			{
				cout<<"! "<<l<<endl;
				break;
			}
			int mid=(l+r)>>1;
		//	assert(mid-l+1<l);
			query(1,mid-l+1,l,mid);
			if(f!=1)
			{
				l=mid+1;
			}
			else r=mid;
		}
	}
}
/*
5 2
5 5 5 1 2
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/