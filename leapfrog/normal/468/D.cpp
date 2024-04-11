//Coded by leapfrog on 2021.10.28 {{{
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
const int N=100005;set<int>nd[N],id;set<pair<int,int> >dd;int nid=0;
struct edge{int to,w,nxt;}e[N<<1];int et,head[N],d[N],p[N];
int n,sz[N],rt,dfn[N],nfd[N],dt,f[N],tag[N];ll rs=0;
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void getrt(int x,int fa)
{
	sz[x]=1;int mx=0;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		getrt(e[i].to,x),sz[x]+=sz[e[i].to],mx=max(mx,sz[e[i].to]);
	mx=max(mx,n-sz[x]);if(mx<=n/2) rt=x;
}
inline void dfs0(int x,int fa)
{
	dfn[x]=++dt,nfd[dt]=x,sz[x]=1,f[x]=fa;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to],rs+=2ll*min(sz[e[i].to],n-sz[e[i].to])*e[i].w;
}
int main()
{
	read(n);for(int i=1,x,y,w;i<n;i++) read(x,y,w),adde(x,y,w),adde(y,x,w);
	if(n==1) return puts("0\n1\n"),0;else if(n==2) return printf("%lld\n2 1\n",2ll*e[head[1]].w),0;
	getrt(1,0),dfs0(rt,0),printf("%lld\n",rs);
	for(int i=head[rt],x;i;i=e[i].nxt)
	{
		++nid,x=e[i].to;for(int l=dfn[x];l<dfn[x]+sz[x];l++) nd[tag[nfd[l]]=nid].insert(nfd[l]);
		id.insert(*nd[nid].begin()),dd.insert(make_pair(d[nid]=n-2*nd[nid].size(),nid));
	}
	nd[tag[rt]=++nid].insert(rt),dd.insert(make_pair(d[nid]=n-2,nid)),id.insert(rt);
	int tg=0;for(int i=1;i<=n;i++)
	{
		int ps=tag[i],tw;dd.erase(make_pair(d[ps],ps));
		if(dd.begin()->first+tg==0&&dd.begin()->second!=tag[rt]) tw=dd.begin()->second;
		else if(tag[*id.begin()]==ps&&i!=rt) tw=tag[*++id.begin()];else tw=tag[*id.begin()];
		int qw=*nd[tw].begin();p[i]=qw,tg--,dd.erase(make_pair(d[tw],tw));
		id.erase(qw),nd[tw].erase(nd[tw].begin());if(!nd[tw].empty()) id.insert(*nd[tw].begin());
		dd.insert(make_pair(++d[ps],ps)),dd.insert(make_pair(++d[tw],tw));
	}
	for(int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
	return 0;
}