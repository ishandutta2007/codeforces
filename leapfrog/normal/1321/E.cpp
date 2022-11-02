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
const int N=200005;int at,bt,n;
struct node{int a,w;char operator<(node y) const {return a<y.a;}}a[N],b[N];
struct moster{int x,y,w;}w[N];
struct segm{int mx,tg;}T[N<<2];
inline void pushup(int x) {T[x].mx=max(T[x<<1].mx,T[x<<1|1].mx);}
inline void allc(int x,int w) {T[x].mx+=w,T[x].tg+=w;}
inline void pushdw(int x) {if(T[x].tg) allc(x<<1,T[x].tg),allc(x<<1|1,T[x].tg),T[x].tg=0;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x].mx=-b[l].w,void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return -2e9;else if(dl<=l&&r<=dr) return T[x].mx;else pushdw(x);
	return max(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
int main()
{
	read(at,bt,n);for(int i=1;i<=at;i++) read(a[i].a,a[i].w);
	for(int i=1;i<=bt;i++) read(b[i].a,b[i].w);
	for(int i=1;i<=n;i++) read(w[i].x,w[i].y,w[i].w);
	sort(a+1,a+at+1),sort(b+1,b+bt+1),build(1,1,bt);int it=1;
	sort(w+1,w+n+1,[](moster a,moster b){return a.x<b.x;});
	int rs=-2e9;for(int i=1;i<=at;i++)
	{
		while(it<=n&&w[it].x<a[i].a)
		{
			int wh=upper_bound(b+1,b+bt+1,(node){w[it].y,0})-b;
			modif(1,1,bt,wh,n,w[it].w),it++;
		}rs=max(rs,T[1].mx-a[i].w);
	}return printf("%d\n",rs),0;
}