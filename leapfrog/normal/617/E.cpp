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
int n,m,K,bl[100005],SZ,a[100005],cnt[2000005];ll rs[100005];
struct segm{int l,r,id;inline bool operator<(segm b) const {return bl[l]^bl[b.l]?bl[l]<bl[b.l]:bl[l]&1?r<b.r:r>b.r;}}q[100005];
inline void ins(int x,ll &nw) {nw+=cnt[x^K],cnt[x]++;}
inline void del(int x,ll &nw) {cnt[x]--,nw-=cnt[x^K];}
int main()
{
	read(n),read(m),read(K),SZ=sqrt(n);
	for(int i=1;i<=n;i++) read(a[i]),bl[i]=(i-1)/SZ+1;
	for(int i=1;i<=m;i++) read(q[i].l),read(q[i].r),q[i].id=i,q[i].l--;
	sort(q+1,q+m+1);for(int i=1;i<=n;i++) a[i]^=a[i-1];
	ll nw=0;for(int l=0,r=-1,i=1;i<=m;i++)
	{
		while(l<q[i].l) del(a[l++],nw);
		while(l>q[i].l) ins(a[--l],nw);
		while(r<q[i].r) ins(a[++r],nw);
		while(r>q[i].r) del(a[r--],nw);
		rs[q[i].id]=nw;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",rs[i]);
	return 0;
}