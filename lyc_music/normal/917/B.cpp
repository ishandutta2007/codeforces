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
//#define int ll
#define N 105
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,x,y;
char ch;
int ru[N];
vector<pa>G[N];
int f[N][N][35];
queue<int>q;
int F[N];
void ad(int x,int y,int w)
{
	G[x].push_back({y,w});
}
bool dfs(int x,int y,int val)
{
	if (~f[x][y][val]) return f[x][y][val];
	bool res=0;
	for (auto U:G[x])
	{
		int u=U.fi,w=U.se;
		if (w<val) continue;
		res|=(dfs(y,u,w)^1);
	}
	f[x][y][val]=res;
	return res;
}
void LYC_music()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>ch;
		ad(x,y,ch-'a'+1);
	}
	memset(f,-1,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			if (dfs(i,j,0))
			cout<<'A';
			else cout<<'B';
		cout<<endl;
	}
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