//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n;ll L[100005],R[100005],tn[300005],ut,op[100005];
struct node{char fg,rv;int sm,ln;}T[1200005];
inline void allf(int x,int c) {T[x].sm=c*T[x].ln,T[x].fg=c,T[x].rv=0;}
inline void allr(int x) {T[x].sm=T[x].ln-T[x].sm,T[x].rv^=1;}
inline void pushf(int x) {if(T[x].fg<2) allf(x<<1,T[x].fg),allf(x<<1|1,T[x].fg),T[x].fg=2;}
inline void pushr(int x) {if(T[x].rv) allr(x<<1),allr(x<<1|1),T[x].rv=0;}
inline void pushdw(int x) {pushf(x),pushr(x);}
inline void build(int x,int l,int r)
{
	T[x]=(node){2,0,0,r-l+1};if(l==r) return;
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allf(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),T[x].sm=T[x<<1].sm+T[x<<1|1].sm;
}
inline void modir(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allr(x);else pushdw(x);
	modir(x<<1,l,(l+r)>>1,dl,dr),modir(x<<1|1,((l+r)>>1)+1,r,dl,dr),T[x].sm=T[x<<1].sm+T[x<<1|1].sm;
}
inline int qry(int x,int l,int r)
{
	if(l==r) return l;else pushdw(x);
	if(T[x<<1].sm!=((l+r)>>1)-l+1) return qry(x<<1,l,(l+r)>>1);
	else return qry(x<<1|1,((l+r)>>1)+1,r);
}
int main()
{
	read(n),tn[++ut]=1,tn[++ut]=1e18;for(int i=1;i<=n;i++)
	{
		read(op[i]),read(L[i]),read(R[i]);
		tn[++ut]=L[i],tn[++ut]=R[i],tn[++ut]=R[i]+1;
	}
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1,build(1,1,ut);
	for(int i=1;i<=n;i++) L[i]=lower_bound(tn+1,tn+ut+1,L[i])-tn,R[i]=lower_bound(tn+1,tn+ut+1,R[i])-tn;
	for(int i=1;i<=n;i++,printf("%lld\n",tn[qry(1,1,ut)]))
		if(op[i]==3) modir(1,1,ut,L[i],R[i]);else modif(1,1,ut,L[i],R[i],2-op[i]);
	return 0;
}