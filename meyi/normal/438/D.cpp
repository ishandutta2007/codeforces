#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct segment_tree{
	int l,r,mx;
	ll sum;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
	t[p].sum=t[ls(p)].sum+t[rs(p)].sum;
}
int a[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].mx=t[p].sum=a[l];
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
inline ll query_sum(int p,int l,int r){
	if(no_intersection)return 0;
	if(is_subset)return t[p].sum;
	return query_sum(ls(p),l,r)+query_sum(rs(p),l,r);
}
inline int query_mx(int p,int l,int r){
	if(no_intersection)return 0;
	if(is_subset)return t[p].mx;
	return max(query_mx(ls(p),l,r),query_mx(rs(p),l,r));
}
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	if(t[p].l==t[p].r){
		t[p].mx%=v;
		t[p].sum=t[p].mx;
		return;
	}
	if(query_mx(ls(p),l,r)>=v)modify(ls(p),l,r,v);
	if(query_mx(rs(p),l,r)>=v)modify(rs(p),l,r,v);
	push_up(p);
}
void modify(int p,int k,int v){
	if(t[p].l>k||k>t[p].r)return;
	if(t[p].l==t[p].r){
		t[p].mx=t[p].sum=v;
		return;
	}
	modify(ls(p),k,v);
	modify(rs(p),k,v);
	push_up(p);
}
int m,n;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	build(1,1,n);
	while(m--){
		ri op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)printf("%lld\n",query_sum(1,x,y));
		else if(op==2)scanf("%d",&z),modify(1,x,y,z);
		else modify(1,x,y);
	}
	return 0;
}