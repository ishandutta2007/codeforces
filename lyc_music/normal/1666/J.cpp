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
#define N 205
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
struct  node
{
	int x,y,z;
	node(int a,int b,int c)
	{
		x=a,y=b,z=c;
	}
	node()
	{
		x=y=z=0;
	}
};
int n,a[N][N];
int s[N][N],f[N][N],rt[N][N];
poly b[N];
int fa[N];
int ans,cnt;
int solve(int l,int r)
{
	if (l>r) return 0;
	if (l==r) return l;
	int now=rt[l][r];
	int x=solve(l,now-1);
	int y=solve(now+1,r);
	fa[x]=now;
	fa[y]=now;
	return now;
}
int calc(int x,int y,int X,int Y)
{
	if (x>y||X>Y)return 0;
	return s[y][Y]-s[x-1][Y]-s[y][X-1]+s[x-1][X-1];
}
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			a[i][j]=read();
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
		}
	}
	for (int len=2;len<=n;len++)
		for (int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			f[i][j]=inf;
			int sm=0;
			for (int k=i;k<=j;k++)
			{
				int del=calc(k+1,j,1,k)+calc(k+1,j,j+1,n)+calc(i,k-1,k,n)+calc(i,k-1,1,i-1);
				if (f[i][k-1]+f[k+1][j]+del<f[i][j])
				{
					f[i][j]=min(f[i][j],f[i][k-1]+del+f[k+1][j]);
					rt[i][j]=k;
				}
				
			}
		}		
	solve(1,n);
	// writeln(f[1][n]);
	for (int i=1;i<=n;i++) writesp(fa[i]);
	puts("");
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