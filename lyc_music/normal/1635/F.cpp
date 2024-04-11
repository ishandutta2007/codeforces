//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf LONG_LONG_MAX
#define mod 998244353
#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,q,a[N],b[N];
int tr[N];
vector<pa>G[N];
int ans[N];
int tp,sta[N];
void update(int x,int y)
{
	while (x<=n) tr[x]=min(tr[x],y),x+=x&-x;;
}
int query(int x)
{
	int res=inf;
	while (x) res=min(res,tr[x]),x-=x&-x;
	return res;
}
void BellaKira()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();b[i]=read();
	}
	for (int i=1;i<=n;i++) tr[i]=inf;
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		G[r].push_back(mp(l,i));
	}
	for (int i=1;i<=n;i++)
	{
		while (tp)
		{
			int x=sta[tp];
			update(n-x+1,(a[i]-a[x])*(b[i]+b[x]));
			if (b[x]>b[i]) tp--;
			else break;
		}
		sta[++tp]=i;
		for (auto u:G[i])
		{
			ans[u.se]=query(n-u.fi+1);
		}
	}
	for (int i=1;i<=q;i++) writeln(ans[i]);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/