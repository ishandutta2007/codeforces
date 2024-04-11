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
const int N=2000005;
struct node{int mn,fg;}T[N<<2];int n,m,a[N],s[N],id[N],tn[N],b[N];
inline void pushup(int x) {T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);}
inline void allc(int x,int w) {T[x].mn+=w,T[x].fg+=w;}
inline void pushdw(int x) {if(T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=0;}
inline void build(int x,int l,int r)
{
	T[x].mn=T[x].fg=0;if(l==r) return;
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 2e9+5;else if(dl<=l&&r<=dr) return T[x].mn;else pushdw(x);
	return min(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
inline void solve()
{
	read(n,m);ll rs=0;
	for(int i=1;i<=n;i++) read(a[i]),id[i]=i,tn[i]=a[i];
	for(int i=1;i<=m;i++) read(b[i]);
	sort(tn+1,tn+n+1),build(1,1,n);
	sort(b+1,b+m+1),sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
	for(int i=1;i<=n;i++) a[i]=lower_bound(tn+1,tn+n+1,a[i])-tn,rs+=query(1,1,n,a[i],a[i]),modif(1,1,n,1,a[i]-1,1);
	int p1=1,p2=1;build(1,0,n);for(int i=1;i<=n;i++) modif(1,0,n,i,n,1);
	for(int i=1;i<=m;i++)
	{
		while(b[i]>=tn[p1]&&p1<=n) modif(1,0,n,id[p1],n,-1),p1++;
		while(b[i]>tn[p2]&&p2<=n) modif(1,0,n,0,id[p2]-1,1),p2++;
		rs+=T[1].mn;
	}
	printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}