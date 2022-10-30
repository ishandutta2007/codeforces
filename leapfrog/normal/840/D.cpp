//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct segm{int ls,rs,sm;}t[10000005];int n,m,a[300005],tn[300005],rt[300005],tc=0;
inline void build(int &x,int l,int r) {t[x=++tc]=(segm){0,0,0};if(l^r) build(t[x].ls,l,(l+r)>>1),build(t[x].rs,((l+r)>>1)+1,r);}
inline void updat(int &x,int od,int l,int r,int dw)
{
	t[x=++tc]=t[od],t[x].sm++;if(l==r) return;
	if(dw<=((l+r)>>1)) updat(t[x].ls,t[od].ls,l,(l+r)>>1,dw);else updat(t[x].rs,t[od].rs,((l+r)>>1)+1,r,dw);
}
inline int query(int x,int y,int l,int r,int dw)
{
	int ww;if(l==r) return tn[l];
	if(t[t[y].ls].sm-t[t[x].ls].sm>dw&&~(ww=query(t[x].ls,t[y].ls,l,(l+r)>>1,dw))) return ww;
	if(t[t[y].rs].sm-t[t[x].rs].sm>dw&&~(ww=query(t[x].rs,t[y].rs,((l+r)>>1)+1,r,dw))) return ww;
	return -1;
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]),tn[i]=a[i];
	sort(tn+1,tn+n+1);int cnt=unique(tn+1,tn+n+1)-tn-1;build(rt[0],1,cnt);
	for(int i=1;i<=n;i++) a[i]=lower_bound(tn+1,tn+cnt+1,a[i])-tn,updat(rt[i],rt[i-1],1,cnt,a[i]);
	for(int l,r,k;m--;) read(l),read(r),read(k),printf("%d\n",query(rt[l-1],rt[r],1,cnt,(r-l+1)/k));
	return 0;
}