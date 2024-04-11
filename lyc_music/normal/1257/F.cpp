//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
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
int a[N],b[N],n;
map<vector<int>,int>Mp;
void dfs(int l,int r,int now)
{
	if (l==r)
	{
		vector<int>g;
		for (int i=1;i<=n;i++) g.push_back(b[i]);
		Mp[g]=now;
		return;
	}
	for (int i=1;i<=n;i++) 
	{
		b[i]++;
		if ((a[i]>>l)&1) b[i]--;
	}
	dfs(l+1,r,now+(1ll<<l));
	for (int i=1;i<=n;i++) 
	{
		b[i]--;
		if ((a[i]>>l)&1) b[i]++;
	}
	for (int i=1;i<=n;i++) 
	{
		if ((a[i]>>l)&1) b[i]++;
	}
	dfs(l+1,r,now);
	for (int i=1;i<=n;i++) 
	{
		if ((a[i]>>l)&1) b[i]--;
	}
}
void dfs1(int l,int r,int now)
{
	if (l==r)
	{
		for (int j=0;j<=30;j++)
		{
			vector<int>g;
			bool bl=1;
			for (int i=1;i<=n;i++)
			{
				if (b[i]>j) 
				{
					bl=0;
					break;
				}
				g.push_back(j-b[i]);
			}
			if (!bl) continue;
			if (Mp[g])
			{
				writeln(now+Mp[g]);
				exit(0);
			}
		}
		return;
	}
	for (int i=1;i<=n;i++) 
	{
		b[i]++;
		if ((a[i]>>l)&1) b[i]--;
	}
	dfs1(l+1,r,now+(1ll<<l));
	for (int i=1;i<=n;i++) 
	{
		b[i]--;
		if ((a[i]>>l)&1) b[i]++;
	}
	for (int i=1;i<=n;i++) 
	{
		if ((a[i]>>l)&1) b[i]++;
	}
	dfs1(l+1,r,now);
	for (int i=1;i<=n;i++) 
	{
		if ((a[i]>>l)&1) b[i]--;
	}
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	dfs(0,15,0);
	dfs1(15,30,0);
	puts("-1");
}
/*

*/