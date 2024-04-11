//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
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
int fa[N],du[N];
set<pa>S[N],now;
int vis[N];
int siz[N];
int n,d;
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void merge(int x,int y)
{
	x=gf(x);
	y=gf(y);
	now.erase({siz[x],x});
	now.erase({siz[y],y});
	siz[y]+=siz[x];
	fa[x]=y;
	now.insert({siz[y],y});
	
}
void LYC_music()
{
	n=read(),d=read();
	for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1,now.insert({1,i});
	for (int i=1;i<=d;i++)
	{
		int x=read(),y=read();
		if (gf(x)!=gf(y))
		{
			merge(x,y);
		}
		auto it=(--now.end());
		int sm=0;
		for (auto u:now) sm+=u.fi-1;
		int res=(*it).fi-1,res1=0;
		while (1)
		{
			if (it==now.begin()) break;
			it--;
			res1++;
			if (sm+res1>i) break;
			res+=(*it).fi;
		}
		writeln(res);
//		writeln(sm);
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