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
#define p 2333
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int h[N],powp[N],z[N],s[N];
vector<int>G[N];
char a[N],b[N],c[N];
int m;
int n;
int gt(int l,int r)
{
	return (h[r]-h[l-1]*powp[r-l+1]%mod+mod)%mod;
}
void BellaKira()
{
	scanf("%[^\n]",a+1);
	scanf("%*[\n]%[^\n]",b+1);
	n=strlen(a+1);
	if (strlen(b+1)!=n) return puts("-1 -1"),void();
	m=2*n+1;
	powp[0]=1;
	for (int i=1;i<=n;i++)
	{
		h[i]=(h[i-1]*p+a[i])%mod;
		powp[i]=powp[i-1]*p%mod;
	}
	reverse(a+1,a+n+1);
	for (int i=1;i<=n;i++) c[i]=a[i];
	c[n+1]='#';
	for (int i=1;i<=n;i++) c[i+n+1]=b[i];
	int l=0,r=0;
	z[1]=m;
	for (int i=2;i<=m;i++)
	{
		if (i<=r) z[i]=min(r-i+1,z[i-l+1]);
		while (i+z[i]<=m&&c[i+z[i]]==c[z[i]+1]) z[i]++;
		// cout<<i<<" "<<z[i]<<endl;
		if (z[i]+i-1>r) l=i,r=z[i]+i-1;
		if (i>n+1)
		{
			if (z[i]+i-1>=i) 
			G[z[i]+i-n-1].push_back(i-n-1);
			// cout<<i-n-1<<"::::"<<z[i]+i-n-1<<endl;
		}
	}
	for (int i=1;i<=n;i++)
		s[i]=(s[i-1]*p+b[i])%mod;
	int nowmx=n+1;
	int ansx=0,ansy=0;
	for (auto u:G[n+1]) nowmx=min(nowmx,u);
	for (int i=n;i>=1;i--)
	{
		if (a[i]!=b[i]) break;
		for (auto u:G[i]) nowmx=min(nowmx,u);
		int u=nowmx;
		// cout<<i<<","<<u<<endl;
		if (u<i)
		{
			if (gt(n-i+2,n-i+1+u-1)==s[u-1])
			{
				ansx=n-i+1;
				ansy=n-i+u+1;
			}
		}
	}
	writesp(ansx-1),writeln(ansy-1);
			
		
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