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
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[200005][25],b[105];
void BellaKira()
{
	int l=read(),r=read();
	int ans=r-l+1;
	for (int j=20;j>=0;j--)
	{
		ans=min(ans,r-l+1-(a[r][j]-a[l-1][j]));
	}
	writeln(ans);
}
signed main()
{
	for (int i=1;i<=200000;i++)
	{
		for (int j=20;j>=0;j--)
		{
			a[i][j]=a[i-1][j];
			if ((i>>j)&1) a[i][j]++;
		}
	}
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/