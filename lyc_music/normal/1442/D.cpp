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
int f[N],tot[N];
int ans;
vector<int>G[N];
int n,m;
void solve(int l,int r)
{
	if (l>r) return;
	if (l==r)
	{
		ans=max(ans,f[m]);
		for (int i=1;i<=tot[l];i++)
		{
			if (i>m) break;
			ans=max(ans,f[m-i]+G[l][i-1]);
		}
		return;
	}
	int mid=l+(r-l)/2;
	vector<int>g(m+1,0);
	for (int i=0;i<=m;i++) g[i]=f[i];
	for (int i=l;i<=mid;i++)
	{
		int x=tot[i],y=G[i][x-1];
		for (int j=m;j>=x;j--)
			f[j]=max(f[j],f[j-x]+y);
	}
	solve(mid+1,r);
	for (int i=0;i<=m;i++) f[i]=g[i];
	for (int i=mid+1;i<=r;i++)
	{
		int x=tot[i],y=G[i][x-1];
		for (int j=m;j>=x;j--)
			f[j]=max(f[j],f[j-x]+y);
	}
	solve(l,mid);
	for (int i=0;i<=m;i++) f[i]=g[i];
}
void LYC_music()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		tot[i]=read();
		for (int j=1;j<=tot[i];j++) 
		{
			G[i].push_back(read());
			if (j!=1) G[i][j-1]+=G[i][j-2];
		}
	}
	memset(f,0xc0,sizeof(f));
	f[0]=0;
	solve(1,n);
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