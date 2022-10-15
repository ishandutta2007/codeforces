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
#define M N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
int ins[N];
int a[N];
int b[N];
int sta[N];
int vis[N];
int tp;
int A[N];
map<int,int>G[N];
int ans;
void dfs(int k)
{
	if (ins[k])
	{
		ans=0;
		return;
	}
	if (vis[k]) return;
	ins[k]=1;
	vis[k]=1;
	sta[++tp]=k;
	for (auto u:G[k])
	{
		if (!ans) return;
		dfs(u.fi);
	}
	ins[k]=0;
}
// namespace F1
// {
	// int A[N];
	// int ans;
	// int Work()
	// {
		// ans=0;
		// poly G;
		// for (int i=1;i<=n;i++)
		// {
			// a[A[i]].push_back(i);
		// }
		// for (int i=1;i<=n;i++)
			// G.push_back(i);
		// for (int i=0;i<n;i++)
		// {
			// poly G1;
			// for (auto u:G)
			// {
				// if (a[u].size()==i) continue;
				// G1.push_back(u);
			// }
			// for (int j=0;j<G1.size();j++)
			// {
				// b[a[G1[j]][i]]=G1[(j+1)%G1.size()];
			// }
			// if (!G1.size()) break;
			// ans+=G1.size()-1;
			// // cout<<"?"<<G1.size()<<endl;
			// G1.swap(G);
		// }
		// for (int i=1;i<=n;i++) a[i].clear();
		// return ans;
	// }
// }
void BellaKira()
{
	n=read();
	ans=1;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		A[a[i]]++;
	}
	for (int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	int now=1;
	for (int i=1;i<=n;i++)
		if (A[i]>A[now]) now=i;
	for (int i=1;i<=n;i++)
		if (a[i]!=now&&b[i]!=now)
			G[a[i]][b[i]]++;
	for (int i=1;i<=n;i++)
	{
		if (vis[i]) continue;
		if (!ans) break;
		dfs(i);
	}
	for (int i=1;i<=n;i++) G[i].clear(),A[i]=0,vis[i]=0,ins[i]=0;
	if (ans)
		puts("AC");
	else puts("WA");
		
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