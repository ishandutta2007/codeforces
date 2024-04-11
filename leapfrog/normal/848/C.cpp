//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}//j<i a[j].x<=a[i].y a[j].y>=a[i].x
struct node{char fg;int x,y,vl,id;}q[1000005];int qt,n,m,a[100005],rt;
ll rs[100005],T[100005];set<int>cl[100005];int ls[100005],nx[100005];
inline void add(int x,int w) {if(x) for(;x<=n;x+=x&(-x)) T[x]+=w;}
inline ll qry(int x) {ll sm=0;for(;x;x-=x&(-x)) sm+=T[x];return sm;}
inline char cmpx(node a,node b) {return a.x<b.x;}
inline char cmpy(node a,node b) {return a.y<b.y;}
inline int getls(int x,int c) {return *(--cl[c].lower_bound(x));}
inline int getnx(int x,int c) {return *cl[c].upper_bound(x);}
inline void ins(int x,int y) {q[++qt]=(node){0,x,ls[x],ls[x]-x,0},ls[x]=y,q[++qt]=(node){0,x,ls[x],x-ls[x],0};}
inline void solve(int l,int r)
{
	int md=(l+r)>>1;if(l==r) return;else solve(l,md),solve(md+1,r);
	int j=l,i=md+1;sort(q+l,q+md+1,cmpx),sort(q+md+1,q+r+1,cmpy);
	while(j<=md&&i<=r)
		if(q[j].x<=q[i].y) {if(!q[j].fg) add(q[j].y,q[j].vl);j++;}
		else {if(q[i].fg) rs[q[i].id]+=qry(n)-qry(q[i].x-1);i++;}
	while(i<=r) {if(q[i].fg) rs[q[i].id]+=qry(n)-qry(q[i].x-1);i++;}
	for(int k=l;k<j;k++) if(!q[k].fg) add(q[k].y,-q[k].vl);
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) cl[i].insert(0),cl[i].insert(n+1);
	for(int i=1;i<=n;i++) read(a[i]),cl[a[i]].insert(i);
	for(int i=1;i<=n;i++) ls[i]=getls(i,a[i]),nx[i]=getnx(i,a[i]),q[++qt]=(node){0,i,ls[i],i-ls[i],0};
	for(int i=1,fg,x,y;i<=m;i++)
	{
		read(fg),read(x),read(y);
		if(!(fg&1)) {++rt,q[++qt]=(node){1,x,y,0,rt};continue;}else if(y==a[x]) continue;
		int nwl=getls(x,y),nwn=getnx(x,y);cl[a[x]].erase(x),cl[y].insert(x),a[x]=y;
		(nx[x]!=n+1?ins(nx[x],ls[x]):void()),(ls[x]?nx[ls[x]]=nx[x]:0);
		(nwl?nx[nwl]=x:0),(nwn!=n+1?ins(nwn,x):void()),ins(x,nwl),nx[x]=nwn;
	}
	solve(1,qt);for(int i=1;i<=rt;i++) printf("%lld\n",rs[i]);
	return 0;
}