//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,Q,K,p3[1000005],p3t,sz[100005],fa[100005];
struct node{int fg,x,y;}q[500005];vector<pair<int,int> >T[2000005];
struct dsub{int x,y,sz;}ds[100005];int dt=0;
inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
inline void mrg(int x,int y)
{
	x=getf(x),y=getf(y);if(x==y) return;else if(sz[x]>sz[y]) swap(x,y);
	ds[++dt]=(dsub){x,y,sz[y]},sz[y]+=sz[x],fa[x]=y;
}
inline void pop(int q) {while(dt>q) fa[ds[dt].x]=ds[dt].x,sz[ds[dt].y]-=sz[ds[dt].x],dt--;}
inline void modif(int x,int l,int r,int dl,int dr,pair<int,int>dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return T[x].push_back(dc);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc);
}
inline void solve(int x,int l,int r)
{
	int ww=dt;for(auto z:T[x]) mrg(z.first,z.second);
	if(l==r) return (q[l].fg==2?printf("%d\n",sz[getf(q[l].x)]):0),pop(ww);
	solve(x<<1,l,(l+r)>>1),solve(x<<1|1,((l+r)>>1)+1,r),pop(ww);
}
int main()
{
	read(n),read(Q),read(K);for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=Q;i++) read(q[i].fg),(q[i].fg<3?read(q[i].x),0:0),(q[i].fg<2?read(q[i].y),0:0);
	p3[++p3t]=1;for(int i=1;i<=Q;i++) if(q[i].fg==3) p3[++p3t]=i;
	for(int i=p3t+1;i<=p3t+K;i++) p3[i]=Q+1;
	for(int i=1;i<=Q;i++) if(q[i].fg==1)
	{
		int x=i,y=p3[upper_bound(p3+1,p3+p3t+1,i)-p3-1+K];
		modif(1,1,Q,x,y-1,make_pair(q[i].x,q[i].y));
		//printf("%d <-> %d : %d ~ %d\n",q[i].x,q[i].y,x,y-1);
	}
	return solve(1,1,Q),0;
}