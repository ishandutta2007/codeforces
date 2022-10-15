//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 3005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st,st1;
int n,m;
int f[N][N];
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
void LYC_music()
{
	cin>>st>>st1;
	n=st.length();
	m=st1.length();
	st=' '+st;
	st1=' '+st1;
	for (int i=1;i<=n;i++)
	{
		if (i<=m)
		{
			if (st[1]==st1[i]) f[i][i]=2;
		} else
			f[i][i]=2;
//		cout<<i<<" "<<i<<" "<<f[i][i]<<endl;
	}
	for (int len=2;len<=n;len++)
		for (int i=1;i<=n;i++)
		{
			int j=i+len-1;
			if (i<=m&&st[len]==st1[i])
			{
				ad(f[i][j],f[i+1][j]);
			}
			else
			if (i>m)
			{
				ad(f[i][j],f[i+1][j]);
			}
			
			if (j<=m&&st1[j]==st[len])
			{
				ad(f[i][j],f[i][j-1]);
			} else
			if (j>m)
			{
				ad(f[i][j],f[i][j-1]);
			}
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	int ans=0;
	for (int i=m;i<=n;i++) ans=(ans+f[1][i])%mod;
	writeln(ans);
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/