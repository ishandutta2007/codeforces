//~~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,q,m,ans;
pa a[N];
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
void BellaKira()
{
	n=read(),q=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=mp(read(),i);
	sort(a+1,a+n+1);
	vector<vector<int>>f(m+5,vector<int>(n+5,0));
	vector<vector<int>>s;
	s=f;
	for (int i=1;i<=n;i++) f[1][i]=1,s[1][i]=(s[1][i-1]+f[1][i])%mod;
	ad(ans,n*((q/n)%mod)%mod);
	m=min((q+n-1)/n,m);
	for (int i=2;i<=m;i++)
	{
		int x=0;
		for (int j=1;j<=n;j++)
		{
			while (a[x].fi<=a[j].fi&&x<=n) x++;
			// cout<<"?"<<j<<" "<<x<<endl;
			ad(f[i][j],s[i-1][x-1]);
		}
		for (int j=1;j<=n;j++)
			ad(s[i][j],s[i][j-1]),ad(s[i][j],f[i][j]);
		ad(ans,s[i][n]*((q/n-i+1)%mod)%mod);
	}
	// cout<<"?"<<ans<<endl;
	int now=0;
	for (int i=1;i<=n;i++)
		if (a[i].se-1<q%n)
		{
			while (a[now].fi<=a[i].fi&&now<=n) now++;
			for (int j=2;j<=m;j++)
				{
					ad(ans,s[j-1][now-1]);
				}
			ad(ans,1);
		}
	writeln(ans);
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
13 1984343432234 32
347580985 506695806 506695806 42598441 347580985 720568974 208035957 385072757 42598441 506695806 42598441 42598441 506695806
*/