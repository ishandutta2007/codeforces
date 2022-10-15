//QwQcOrZ yyds!!!nmsl
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
//#define int ll
#define N 5005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st;
int n;
ll f[N][N],s[N][N];
int lcp[N][N];
bool cmp(int x,int y,int len)
{
	if (lcp[x][y]>=len) return 0;
	if (st[x+lcp[x][y]]>st[y+lcp[x][y]]) return 0;
	return 1;
}
signed main()
{
	IOS;
	cin>>n;
	cin>>st;
	st='0'+st;
	f[0][0]=1;
	s[0][0]=1;
	for (int i=n;i>=1;i--)
		for (int j=n;j>=1;j--)
			if (st[i]==st[j])	
				lcp[i][j]=lcp[i+1][j+1]+1;
			else lcp[i][j]=0;
	for (int r=1;r<=n;r++)
	{
		for (int l=1;l<=n;l++)
		{
			if (st[l]=='0')
			{
				f[l][r]=0;
				s[l][r]=s[l-1][r];
				continue;
			}
			if (r<2*(r-l+1))
			{
				f[l][r]=s[l-1][l-1];
			} else
			{
				f[l][r]=(s[l-1][l-1]-s[l-(r-l+1)][l-1]+mod)%mod;
				if (cmp(l-(r-l+1),l,r-l+1))
				{
					f[l][r]=(f[l][r]+f[l-(r-l+1)][l-1])%mod;
				}
			}
			s[l][r]=(f[l][r]+s[l-1][r])%mod;
		}
	}
	writeln(s[n][n]);
}
/*

*/