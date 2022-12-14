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
int n,m,a[N],v[N],vv[N],p[N],pp[N];
bool cmp(int x,int y)
{
	return v[x]<v[y];
}bool cmp1(int x,int y)
{
	return vv[x]<vv[y];
}
void BellaKira()
{
	n=read();m=read();
	int mn=inf,mx=0;
	int sm=0;
	for (int i=1;i<=n;i++)
		a[i]=read(),mn=min(mn,a[i]),mx=max(mx,a[i]),sm+=abs(a[i]-a[i-1])*(i!=1);
	for (int i=1;i<=n+1;i++)
	{
		if (i==1) v[i]=abs(a[1]-1);
		else if (i==n+1) v[i]=abs(a[n]-1);
		else v[i]=abs(a[i]-1)+abs(a[i-1]-1)-abs(a[i]-a[i-1]);
		if (mn<=1) v[i]=0;
		p[i]=i;
	}
	sort(p+1,p+n+2,cmp);
	for (int i=1;i<=n+1;i++)
	{
		if (i==1) vv[i]=abs(a[1]-m);
		else if (i==n+1) vv[i]=abs(a[n]-m);
		else vv[i]=abs(a[i]-m)+abs(a[i-1]-m)-abs(a[i]-a[i-1]);
		if (mx>=m) vv[i]=0;
		pp[i]=i;
	}
	sort(pp+1,pp+n+2,cmp1);
	int ans=inf;
	if (p[1]!=pp[1])
	ans=min(v[p[1]]+vv[pp[1]],ans);
	if (p[1]!=pp[2])
	ans=min(v[p[1]]+vv[pp[2]],ans);
	if (p[2]!=pp[1])
	ans=min(v[p[2]]+vv[pp[1]],ans);
	writeln(ans+sm);
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