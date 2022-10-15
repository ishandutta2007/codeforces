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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
// #define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,C,c[N],d[N],h[N];
int a[N];
int p[N];
int ans[N];
int m;
void BellaKira()
{
	n=read(),C=read();
	for (int i=1;i<=n;i++)
	{
		c[i]=read();
		int v=read()*read();
		a[c[i]]=max(a[c[i]],v);
	}
	for (int i=1;i<=C;i++)
		for (int j=1;j*i<=C;j++)
			a[j*i]=max(a[j*i],a[i]*j);
	for (int i=1;i<=C;i++)
	{
		a[i]=max(a[i],a[i-1]);
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		int D=read(),H=read();
		int l=1,r=C;
		int now=C+1;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (D*H<a[mid])
			{
				now=mid;
				r=mid-1;
			} else l=mid+1;
		}
		if (now==C+1) writesp(-1);
		else writesp(now);
	}
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