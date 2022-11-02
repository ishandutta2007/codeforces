//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int vl,tg,ls,rs;}t[5000005];
int n,k,Q,a[300005],lg[200005],st[200005][25],tt=0,rt=0;
inline int qry(int l,int r) {int g=lg[r-l+1];return min(st[l][g],st[r-(1<<g)+1][g]);}
inline int rqry(int l,int r)
{
	int le=(l-1)/n+1,ri=(r-1)/n+1,L=(l-1)%n+1,R=(r-1)%n+1;if(le==ri) return qry(L,R);
	if(le+1==ri) return min(qry(L,n),qry(1,R));else return qry(1,n);
}
inline void New(int &x,int l,int r) {if(!x) t[x=++tt]=(node){rqry(l,r),0,0,0};}
inline void allc(int x,int c) {if(c) t[x].vl=t[x].tg=c;}
inline void down(int x,int l,int r) {New(t[x].ls,l,(l+r)>>1),New(t[x].rs,((l+r)>>1)+1,r),allc(t[x].ls,t[x].tg),allc(t[x].rs,t[x].tg),t[x].tg=0;}
inline void motif(int &x,int l,int r,int dl,int dr,int dc)
{
	New(x,l,r);if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else down(x,l,r);
	motif(t[x].ls,l,(l+r)>>1,dl,dr,dc),motif(t[x].rs,((l+r)>>1)+1,r,dl,dr,dc),t[x].vl=min(t[t[x].ls].vl,t[t[x].rs].vl);
}
inline int query(int &x,int l,int r,int dl,int dr)
{
	New(x,l,r);if(l>dr||dl>r) return 1e9;else if(dl<=l&&r<=dr) return t[x].vl;else down(x,l,r);
	return min(query(t[x].ls,l,(l+r)>>1,dl,dr),query(t[x].rs,((l+r)>>1)+1,r,dl,dr));
}
inline void debug(int x,int l,int r)
{
	if(x) printf("%d : [ %d , %d ] & %d\n",x,l,r,t[x].vl);
	if(l^r) down(x,l,r),debug(t[x].ls,l,(l+r)>>1),debug(t[x].rs,((l+r)>>1)+1,r);
}
int main()
{
	lg[0]=-1,read(n),read(k);
	for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) read(st[i][0]);
	for(int i=1;i<=20;i++) for(int j=1;j+(1<<(i-1))<=n;j++) st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
//	printf("%d , %d , %d , %d , %d , %d\n",rqry(1,1),rqry(1,2),rqry(1,3),rqry(2,2),rqry(2,3),rqry(3,3));
	read(Q),New(rt,1,n*k);for(int fg,l,r,c;Q--;)
	{
		read(fg),read(l),read(r);//debug(rt,1,n);
		if(fg&1) read(c),motif(rt,1,n*k,l,r,c);else printf("%d\n",query(rt,1,n*k,l,r));
	}
	return 0;
}