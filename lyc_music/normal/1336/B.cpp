//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e19
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,q,a[N],b[N],c[N];
void LYC_music()
{
	n=read(),m=read(),q=read();
	int nn=n,mm=m,qq=q;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	for (int i=1;i<=q;i++) c[i]=read();
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-b-1;
	sort(c+1,c+q+1);
	q=unique(c+1,c+q+1)-c-1;
	int ans=inf;
	for (int i=1;i<=n;i++)
	{
		int x=lower_bound(c+1,c+q+1,a[i])-c;
		if (x<=q)
		{
			int y=lower_bound(b+1,b+m+1,(a[i]+c[x]+1)/2)-b;
//			cout<<"?"<<i<<" "<<y<<" "<<m<<endl;
			if (y>=1&&y<=m)
			{
				ans=min(ans,(a[i]-b[y])*(a[i]-b[y])+(b[y]-c[x])*(b[y]-c[x])+(c[x]-a[i])*(c[x]-a[i]));
			}
			y--;
			if (y>=1&&y<=m)
			{
				ans=min(ans,(a[i]-b[y])*(a[i]-b[y])+(b[y]-c[x])*(b[y]-c[x])+(c[x]-a[i])*(c[x]-a[i]));
			}
		}
	}
	swap(m,q);
	swap(b,c);
	for (int i=1;i<=n;i++)
	{
		int x=lower_bound(c+1,c+q+1,a[i])-c;
		if (x<=q)
		{
			int y=lower_bound(b+1,b+m+1,(a[i]+c[x]+1)/2)-b;
//			cout<<"?"<<i<<" "<<y<<" "<<m<<endl;
			if (y>=1&&y<=m)
			{
				ans=min(ans,(a[i]-b[y])*(a[i]-b[y])+(b[y]-c[x])*(b[y]-c[x])+(c[x]-a[i])*(c[x]-a[i]));
			}
			y--;
			if (y>=1&&y<=m)
			{
				ans=min(ans,(a[i]-b[y])*(a[i]-b[y])+(b[y]-c[x])*(b[y]-c[x])+(c[x]-a[i])*(c[x]-a[i]));
			}
		}
	}
	swap(m,q);
	swap(b,c);
	
	
	for (int i=1;i<=m;i++)
	{
		int x=lower_bound(c+1,c+q+1,b[i])-c;
		if (x<=q)
		{
			int y=lower_bound(a+1,a+n+1,(b[i]+c[x]+1)/2)-a;
			if (y>=1&&y<=n)
			{
				ans=min(ans,(b[i]-a[y])*(b[i]-a[y])+(a[y]-c[x])*(a[y]-c[x])+(c[x]-b[i])*(c[x]-b[i]));
			}
			y--;
			if (y>=1&&y<=n)
			{
				ans=min(ans,(b[i]-a[y])*(b[i]-a[y])+(a[y]-c[x])*(a[y]-c[x])+(c[x]-b[i])*(c[x]-b[i]));
			}
		}
	}
	swap(a,c);
	swap(n,q);
	for (int i=1;i<=m;i++)
	{
		int x=lower_bound(c+1,c+q+1,b[i])-c;
		if (x<=q)
		{
			int y=lower_bound(a+1,a+n+1,(b[i]+c[x]+1)/2)-a;
			if (y>=1&&y<=n)
			{
				ans=min(ans,(b[i]-a[y])*(b[i]-a[y])+(a[y]-c[x])*(a[y]-c[x])+(c[x]-b[i])*(c[x]-b[i]));
			}
			y--;
			if (y>=1&&y<=n)
			{
				ans=min(ans,(b[i]-a[y])*(b[i]-a[y])+(a[y]-c[x])*(a[y]-c[x])+(c[x]-b[i])*(c[x]-b[i]));
			}
		}
	}
	swap(a,c);
	swap(n,q);
	
	for (int i=1;i<=q;i++)
	{
		int x=lower_bound(a+1,a+n+1,c[i])-a;
		if (x<=n)
		{
			int y=lower_bound(b+1,b+m+1,(c[i]+a[x]+1)/2)-b;
			if (y>=1&&y<=m)
			{
				ans=min(ans,(c[i]-b[y])*(c[i]-b[y])+(b[y]-a[x])*(b[y]-a[x])+(a[x]-c[i])*(a[x]-c[i]));
			}
			y--;
			if (y>=1&&y<=m)
			{
				ans=min(ans,(c[i]-b[y])*(c[i]-b[y])+(b[y]-a[x])*(b[y]-a[x])+(a[x]-c[i])*(a[x]-c[i]));
			}
		}
	}
	swap(a,b);
	swap(n,m);
	for (int i=1;i<=q;i++)
	{
		int x=lower_bound(a+1,a+n+1,c[i])-a;
		if (x<=n)
		{
			int y=lower_bound(b+1,b+m+1,(c[i]+a[x]+1)/2)-b;
			if (y>=1&&y<=m)
			{
				ans=min(ans,(c[i]-b[y])*(c[i]-b[y])+(b[y]-a[x])*(b[y]-a[x])+(a[x]-c[i])*(a[x]-c[i]));
			}
			y--;
			if (y>=1&&y<=m)
			{
				ans=min(ans,(c[i]-b[y])*(c[i]-b[y])+(b[y]-a[x])*(b[y]-a[x])+(a[x]-c[i])*(a[x]-c[i]));
			}
		}
	}
	swap(a,b);
	swap(n,m);
	
	writeln(ans);
	for (int i=1;i<=nn;i++) a[i]=0;
	for (int i=1;i<=mm;i++) b[i]=0;
	for (int i=1;i<=qq;i++) c[i]=0;
}
signed main()
{
	int T=read();
	while (T--)
	{
		LYC_music();
	}
}
/*

*/