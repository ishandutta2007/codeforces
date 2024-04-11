//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct seg{int l,r,w;char operator<(seg b) const {return w<b.w;}}a[300005];
struct segm{int fg,mn;}T[4000005];int n,m;
inline void pushup(int x) {T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);}
inline void allc(int x,int c) {T[x].fg+=c,T[x].mn+=c;}
inline void pushdw(int x) {if(T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=0;}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(dl>r||l>dr) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i].l),read(a[i].r),read(a[i].w),a[i].r--;
	sort(a+1,a+n+1),a[n+1].w=1e9;int l=1,r=0,rs=1e9;
	//for(int i=1;i<=n;i++) printf("%d %d %d\n",a[i].l,a[i].r,a[i].w);
	while(r<n&&!T[1].mn) r++,modif(1,1,m-1,a[r].l,a[r].r,1);
	rs=min(rs,a[r].w-a[l].w);for(l++;l<=n;l++)
	{
		modif(1,1,m-1,a[l-1].l,a[l-1].r,-1);
		while(r<n&&!T[1].mn) r++,modif(1,1,m-1,a[r].l,a[r].r,1);
		if(T[1].mn) rs=min(rs,a[r].w-a[l].w);
		//printf("%d %d : %d\n",l,r,a[r].w-a[l].w);
	}
	return printf("%d\n",rs),0;
}