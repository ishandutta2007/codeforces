#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct node{
	ll mn,mx,sum;
	inline node operator+(const node &k){
		return {min(mn,sum+k.mn),max(mx,sum+k.mx),sum+k.sum};
	}
};
struct segment_tree{
	int l,r;
	node v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=t[ls(p)].v+t[rs(p)].v;
}
int a[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].v={a[l],a[l],a[l]};
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
inline node query(int p,int l,int r){
	if(no_intersection)return {0,0,0};
	if(is_subset)return t[p].v;
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int m,n;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1,x;i<=n;++i)scanf("%d",&x),a[i]=x-a[i];
	build(1,1,n);
	while(m--){
		ri l,r;
		scanf("%d%d",&l,&r);
		node tmp=query(1,l,r);
		if(tmp.mn||tmp.sum)puts("-1");
		else printf("%lld\n",tmp.mx);
	}
	return 0;
}