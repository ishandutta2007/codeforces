//{{{
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
const int N=100005;ll t[N],vl[N];char vs[N];
multiset<ll>st[N],sx,sn;int f[N],n,Q,dg[N];
inline void del(int x)
{
	if(vs[x]||st[x].empty()) return;else vs[x]=1;
	sx.erase(sx.find(*--st[x].end()+t[x]/(dg[x]+1)));
	sn.erase(sn.find(*st[x].begin()+t[x]/(dg[x]+1)));
}
inline void add(int x)
{
	if(!vs[x]||st[x].empty()) return;else vs[x]=0;
	sx.insert(*--st[x].end()+t[x]/(dg[x]+1));
	sn.insert(*st[x].begin()+t[x]/(dg[x]+1));
}
inline void work(int u,int y)
{
	int x=f[u],fx=f[x],ffx=f[fx],fy=f[y],ffy=f[fy];
	del(x),del(fx),del(ffx),del(y),del(fy),del(ffy);
	st[x].erase(st[x].find(vl[u]));
	st[fx].erase(st[fx].find(vl[x]));//x 
	vl[x]-=t[u]/(dg[u]+1);
	vl[x]-=t[x]-t[x]/(dg[x]+1)*dg[x];
	vl[x]+=t[x]-t[x]/dg[x]*(dg[x]-1);
	st[fx].insert(vl[x]);
	st[ffx].erase(st[ffx].find(vl[fx]));//fx 
	vl[fx]-=t[x]/(dg[x]+1),vl[fx]+=t[x]/dg[x];
	st[ffx].insert(vl[fx]);
	dg[x]--,dg[y]++,f[u]=y,st[y].insert(vl[u]);//------------
	st[fy].erase(st[fy].find(vl[y]));
	vl[y]+=t[u]/(dg[u]+1);
	vl[y]+=t[y]-t[y]/(dg[y]+1)*dg[y];
	vl[y]-=t[y]-t[y]/dg[y]*(dg[y]-1);
	st[fy].insert(vl[y]);
	st[ffy].erase(st[ffy].find(vl[fy]));
	vl[fy]+=t[y]/(dg[y]+1),vl[fy]-=t[y]/dg[y];
	st[ffy].insert(vl[fy]);
	add(x),add(fx),add(ffx),add(y),add(fy),add(ffy);
}
int main()
{
	read(n,Q);for(int i=1;i<=n;i++) read(t[i]),dg[i]=1;
	for(int i=1;i<=n;i++) read(f[i]),dg[f[i]]++;
	for(int i=1;i<=n;i++) vl[i]+=t[i]-t[i]/(dg[i]+1)*dg[i];
	for(int i=1;i<=n;i++) vl[f[i]]+=t[i]/(dg[i]+1);
	for(int i=1;i<=n;i++) st[f[i]].insert(vl[i]);
	for(int i=1;i<=n;i++) vs[i]=1,add(i);
	for(int i=1,fg,x,y;i<=Q;i++)
	{
		read(fg);if(fg==1) read(x,y),work(x,y);
		else if(fg==3) printf("%lld %lld\n",*sn.begin(),*--sx.end());
		else read(x),printf("%lld\n",vl[x]+t[f[x]]/(dg[f[x]]+1));
		//printf("?? %lld ; %lld : %lld\n",vl[4],t[f[4]],t[f[4]]/(dg[f[4]]+1));
	}return 0;
}