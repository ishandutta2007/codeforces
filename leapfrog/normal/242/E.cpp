//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int len,vl,lz;}t[27][400005];int n,Q,a[400005];
inline void pushup(int id,int x) {t[id][x].vl=t[id][x<<1].vl+t[id][x<<1|1].vl;}
inline void allchg(int id,int x,int c) {if(c) t[id][x].lz^=1,t[id][x].vl=t[id][x].len-t[id][x].vl;}
inline void pushdw(int id,int x) {allchg(id,x<<1,t[id][x].lz),allchg(id,x<<1|1,t[id][x].lz),t[id][x].lz=0;}
inline void build(int id,int x,int l,int r,int *a)
{
	t[id][x].len=r-l+1;if(l==r) return(void)(t[id][x].vl=(a[l]>>id)&1);
	build(id,x<<1,l,(l+r)>>1,a),build(id,x<<1|1,((l+r)>>1)+1,r,a),pushup(id,x);
}
inline void motif(int id,int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allchg(id,x,1);else pushdw(id,x);
	motif(id,x<<1,l,(l+r)>>1,dl,dr),motif(id,x<<1|1,((l+r)>>1)+1,r,dl,dr),pushup(id,x);
}
inline int query(int id,int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return t[id][x].vl;else pushdw(id,x);
	return query(id,x<<1,l,(l+r)>>1,dl,dr)+query(id,x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=0;i<=21;i++) build(i,1,1,n,a);
	for(read(Q);Q--;)
	{
		int fg,l,r,x;long long rs=0;read(fg),read(l),read(r);
		if(fg==2) {read(x);for(int i=0;i<=21;i++) if((x>>i)&1) motif(i,1,1,n,l,r);}
		else {for(int i=0;i<=21;i++) rs+=((long long)query(i,1,1,n,l,r))<<i;printf("%lld\n",rs);}
	}
	return 0;
}