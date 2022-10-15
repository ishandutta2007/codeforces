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
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int ffa[N];
poly G[N];
int n;
int s;
int dep[N];
int oo[N];
int m;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	// cout<<k<<","<<fa<<endl;
	ffa[k]=fa;
	dep[k]=dep[fa]+1;
	oo[k]=oo[fa];
	if (dep[k]==2) oo[k]=k;
	for (auto u:G[k])
	{
		if (dep[u]>=2&&oo[k]!=oo[u])
		{
			poly x,y;
			int now=u;
			x.clear(),y.clear();
			while (now!=-1)
			{
				x.push_back(now);
				// cout<<"???"<<now<<" "<<ffa[now]<<endl;
				now=ffa[now];
			}
			now=k;
			while (now!=-1)
			{
				y.push_back(now);
				now=ffa[now];
			}
			puts("Possible");
			reverse(x.begin(),x.end());
			reverse(y.begin(),y.end());
			y.push_back(u);
			writeln(x.size());
			for (auto u:x) writesp(u);
			puts("");
			// cout<<"???"<<endl;
			writeln(y.size());
			for (auto u:y) writesp(u);
			exit(0);
		}
		if (!ffa[u])
		dfs(u,k);
	}
}		 
void BellaKira()
{
	n=read();m=read();s=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		ad(u,v);
	}
	dfs(s,-1);
	cout<<"Impossible"<<endl;
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