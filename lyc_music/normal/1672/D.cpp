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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N];
int f[N],g[N];
int vis[N];
poly G[N];
int cnt[N];
int b[N];
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	int j=0,now=0;
	int ans=1;
	for (int i=1;i<=n;i++)
	{
		while (G[a[j]].empty()||a[j]!=b[i])
		{
			j++;
			if (j>n)
			{
				ans=0;
				break;
			}
			G[a[j]].push_back(j);
		}
		if (!ans) break;
		G[a[j]].pop_back();
	}
	if (ans) puts("YES");
	else cout<<"NO"<<endl;
	for (int i=1;i<=n;i++) G[i].clear();
	
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/