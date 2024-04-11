//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
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
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fa[N],faa[N],n,m,mm;
vector<int>S,S1;
vector<pa>ans;
int gf(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=gf(fa[x]);
}
int gff(int x)
{
	if (faa[x]==x) return x;
	return faa[x]=gff(faa[x]);
}
signed main()
{
	n=read(),m=read(),mm=read();
	for (int i=1;i<=n;i++) fa[i]=i,faa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (gf(u)!=gf(v)) fa[fa[u]]=fa[v];
	}
	for (int i=1;i<=mm;i++)
	{
		int u=read(),v=read();
		if (gff(u)!=gff(v)) faa[faa[u]]=faa[v];
	}
	for (int i=2;i<=n;i++)
		if (gf(i)!=gf(1)&&gff(i)!=gff(1)) 
		{
			fa[fa[i]]=fa[1];
			faa[faa[i]]=faa[1];
			ans.push_back({1,i});
		}
	for (int i=2;i<=n;i++)
		if (gf(i)!=gf(1)) S.push_back(i),fa[fa[i]]=fa[1];
		else if (gff(i)!=gff(1)) S1.push_back(i),faa[faa[i]]=faa[1];
	if (min(S.size(),S1.size())>0)
	{
		for (int i=0;i<min(S.size(),S1.size());i++)
		{
			ans.push_back({S[i],S1[i]});
		}
	}
	writeln(ans.size());
	for (auto u:ans) writesp(u.fi),writeln(u.se);
}
/*

*/