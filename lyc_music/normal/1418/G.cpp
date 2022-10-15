//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define foor(i,a,b) for (int i=(a);i<=(b);i++)
#define door(i,a,b) for (int i=(a);i>=(b);i--)
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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
mt19937_64 rnd(1145141919);
int a[N];
ull s[N];
int n;
int ls[N];
vector<int>G[N];
ull x;
ull val[N][4];
int ans;
unordered_map<ull,int>Mp;
void update(int l,int r,ull x)
{
	s[l]^=x;
	s[r+1]^=x;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		a[i]=read();
		if (G[a[i]].size()==0)
		{
			ls[i]=0;
		} else ls[i]=G[a[i]][G[a[i]].size()-1];
		G[a[i]].push_back(i);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<3;j++)
			val[i][j]=rnd();
	}
	for (int i=1;i<=n;i++)
	{
		int l=0,t=0;
		for (auto u:G[i])
		{
			update(l,u-1,val[i][t]);
			t++;t%=3;
			l=u;
		}
		update(l,n,val[i][t]);
		x^=val[i][0];
	}
	int now=-1;
	Mp[x]++;
	for (int i=1;i<=n;i++)
	{
		s[i]^=s[i-1];
		int p=ls[ls[ls[i]]]-1;
		while (now<p) now++,Mp[s[now]]--;
		ans+=Mp[s[i]];
		Mp[s[i]]++;
	}
	writeln(ans);
}
/*

*/