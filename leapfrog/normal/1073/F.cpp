//Coded by leapfrog {{{
//Gened on 2021.10.25
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;int n,dep[N],f[N],dg[N];char fg[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
inline void dfs0(int x,int fa)
{
	f[x]=fa,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
}
inline int bruteLCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=f[x];
	while(x^y) x=f[x],y=f[y];
	return x;
}
typedef pair<int,int> pi;pi fs,sc;
inline void chk(pi g) {if(fs<=g) sc=fs,fs=g;else if(sc<=g) sc=g;}
inline pi sub(int x,int fa,int dep)
{
	pi rs=make_pair(dep,x);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) rs=max(rs,sub(e[i].to,x,dep+1));
	return rs;
}
inline void solve(int x,int fa,int lim,int dep)
{
	lim=(dep==lim)&&dg[x]>2?-1:lim;
	if(lim==-1&&dg[x]>1)
	{
		pi ffs,ssc;ffs=ssc=make_pair(0,0);
		for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		{
			pi sb=sub(e[i].to,x,dep+1);
			if(sb>=ffs) ssc=ffs,ffs=sb;else if(sb>=ssc) ssc=sb;
		}
		if(ffs.first+ssc.first>=fs.first+sc.first) fs=ffs,sc=ssc;
		return;
	}
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) solve(e[i].to,x,lim,dep+1);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	int cn=0;for(int i=1;i<=n;i++) cn+=(fg[i]=(dg[i]>=3));
	if(!cn)
	{
		int fs=0,sc=0;for(int i=1;i<=n;i++) if(dg[i]==1) (fs?sc:fs)=i;
		return printf("%d %d\n%d %d\n",fs,fs,e[head[fs]].to,sc),0;
	}
	if(cn==1)
	{
		int fs=0,sc=0,tr=0;for(int i=1;i<=n;i++) if(dg[i]==1) fs?(sc?tr:sc):fs=i;
		return printf("%d %d\n%d %d\n",fs,sc,f[bruteLCA(fs,sc)],tr),0;
	}
	dfs0(1,0);int r1=0;for(int i=1;i<=n;i++) if(fg[i]&&dep[i]>=dep[r1]) r1=i;
	dfs0(r1,0);int r2=0;for(int i=1;i<=n;i++) if(fg[i]&&dep[i]>=dep[r2]) r2=i;
	int dx=dep[r2]-dep[r1],md=r2;for(int qw=dx>>1;qw;qw--,md=f[md]);
	if(dx&1)
	{
		fs=sc=make_pair(0,0),solve(md,f[md],dx>>1,0);pi a=fs,b=sc;
		fs=sc=make_pair(0,0),solve(f[md],md,dx>>1,0);pi c=fs,d=sc;
		return printf("%d %d\n%d %d\n",a.second,c.second,b.second,d.second),0;
	}
	else
	{
		pi a,b,c,d;a=b=c=d=make_pair(0,0);
		for(int i=head[md];i;i=e[i].nxt)
		{
			fs=sc=make_pair(0,0),solve(e[i].to,md,dx>>1,1);
			if(fs.first+sc.first>=a.first+b.first) c=a,d=b,a=fs,b=sc;
			else if(fs.first+sc.first>=c.first+d.first) c=fs,d=sc;
		}
		return printf("%d %d\n%d %d\n",a.second,c.second,b.second,d.second),0;
	}
}