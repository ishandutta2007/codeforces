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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
pa a[N];
int c[N];
bool cmp(int x,int y)
{
	return c[x]<c[y];
}
void BellaKira()
{
	poly g;
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		c[i]=read();
		a[i].fi=read(),a[i].se=i;
	}
	sort(a+1,a+m+1);
	int ans=0;
	for (int i=1;i<=2*n;i++)
		ans+=a[i].fi,g.push_back(a[i].se);
		sort(g.begin(),g.end(),cmp);
	writeln(ans);
	for (int i=0;i<g.size()-i-1;i++)
	{
		writesp(g[i]),writesp(g[g.size()-i-1]);
		puts("");
	}
	puts("");
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/