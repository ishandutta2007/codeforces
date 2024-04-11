//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;typedef long double ld;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[300005],s1[300005],s2[300005],t1,t2;ll res=0;
struct segm{int mn,cn,fg;}T[1200005];const int INF=1e9+5;
inline segm operator+(segm a,segm b) {segm r=a.mn<b.mn?a:a.mn>b.mn?b:(segm){a.mn,a.cn+b.cn,0};return r.fg=0,r;}
inline void allc(int x,int fg) {T[x].mn+=fg,T[x].fg+=fg;}
inline void pushdw(int x) {if(T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=0;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x]=(segm){l,1,0},void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]+T[x<<1|1];
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),T[x]=T[x<<1]+T[x<<1|1];
}
int main()
{
	read(n);for(int i=1,x,y;i<=n;i++) read(x),read(y),a[x]=y;
	build(1,1,n);for(int i=1;i<=n;res+=T[1].cn,s1[++t1]=i,s2[++t2]=i++)
	{
		for(;t1&&a[s1[t1]]<a[i];t1--) modif(1,1,n,s1[t1-1]+1,s1[t1],a[i]-a[s1[t1]]);
		for(;t2&&a[s2[t2]]>a[i];t2--) modif(1,1,n,s2[t2-1]+1,s2[t2],a[s2[t2]]-a[i]);
	}
	return printf("%lld\n",res),0;
}