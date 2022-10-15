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
#define mod 1000000007
#define int ll
#define N 2005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
string st,st1;
int f[N][N<<1];
int g[N][N<<1];
void BellaKira()
{
	cin>>n;
	cin>>st>>st1;
	for (int i=1;i<n;i+=2)
		if (st[i]!='?') st[i]='0'+(1-(st[i]-'0'));
	for (int i=1;i<n;i+=2)
		if (st1[i]!='?') st1[i]='0'+(1-(st1[i]-'0'));
	// cout<<st<<" "<<st1<<endl;
	f[0][n]=1;
	for (int i=1;i<=n;i++)
		for (int j=-n;j<=n;j++)
			for (int x=0;x<=1;x++)
				for (int y=0;y<=1;y++)
				{
					if (!f[i-1][j+n]) continue;
					if (st[i-1]!='?'&&st[i-1]-'0'!=x) continue;
					if (st1[i-1]!='?'&&st1[i-1]-'0'!=y) continue;
					int nxt=j+y-x;
					if (nxt>=-n&&nxt<=n)
					{
						// cout<<i<<" "<<j+n<<" "<<nxt<<" "<<f[i-1][j+n]<<" "<<g[i-1][j+n]<<" "<<f[i-1][j+n]<<endl;
						nxt+=n;
						// cout<<"!"<<f[i][nxt]<<" "<<g[i][nxt]<<endl;
						f[i][nxt]=(f[i][nxt]+f[i-1][j+n])%mod;
						g[i][nxt]=(g[i][nxt]+f[i-1][j+n]*abs(nxt-n)%mod+g[i-1][j+n])%mod;
						// cout<<"!"<<f[i][nxt]<<" "<<g[i][nxt]<<endl;
					}
				}
	cout<<g[n][n]<<endl;
	for (int i=0;i<=n;i++)
		for (int j=-n;j<=n;j++)
			f[i][j+n]=g[i][j+n]=0;
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/