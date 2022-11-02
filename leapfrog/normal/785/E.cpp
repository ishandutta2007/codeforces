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
int n,Q,a[200005],L[555],R[555],bl[200005];ll res=0;vector<int>v[555];
inline void modif(int x,int c)
{
	/*printf("---------\nchange %d from %d to %d\nthe seg is ",x,a[x],c);
	for(auto i:v[bl[x]]) printf("%d ",i);
	putchar('\n');*/
	v[bl[x]].erase(lower_bound(v[bl[x]].begin(),v[bl[x]].end(),a[x]));
	v[bl[x]].insert(upper_bound(v[bl[x]].begin(),v[bl[x]].end(),c),c);
}
inline int calc(int l,int r,int c)
{
	int le=bl[l],ri=bl[r],res=0;if(l>r) return 0;
	if(le==ri) {for(int i=l;i<=r;i++) res+=a[i]<c;return res;}
	for(int i=l;i<=R[le];i++) res+=a[i]<c;
	for(int i=L[ri];i<=r;i++) res+=a[i]<c;
	for(int i=le+1;i<ri;i++) res+=lower_bound(v[i].begin(),v[i].end(),c)-v[i].begin();
	return res;
}
inline void Swap(int x,int y)
{
	if(x==y) return;else res+=2ll*(calc(x+1,y-1,a[y])-calc(x+1,y-1,a[x]));
	if(a[x]<a[y]) res++;else res--;
	if(bl[x]^bl[y]) modif(x,a[y]),modif(y,a[x]);
	swap(a[x],a[y]);
}
signed main()
{
	read(n),read(Q);const int sz=sqrt(n);int blc=0;
	for(int i=1;i<=n;i++) v[bl[i]=(i-1)/sz+1].push_back(a[i]=i);
	for(int i=1;i<=n+1;i++) if(bl[i]^bl[i-1]) {R[blc]=i-1;if(i^(n+1)) L[++blc]=i;}
	for(int l,r;Q--;) read(l),read(r),Swap(min(l,r),max(l,r)),printf("%lld\n",res);
	return 0;
}