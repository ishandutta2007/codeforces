#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],b[maxn],n;
struct segment_tree{
	int l,r;
	ll v,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=max(t[ls(p)].v,t[rs(p)].v);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
inline void add_tag(int p,ll v){
	t[p].v+=v;
	t[p].tag+=v;
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=0;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,ll v){
	if(no_intersection)return;
	if(is_subset){
		add_tag(p,v);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
inline ll query(int p,int l,int r){
	if(no_intersection)return INT_MIN;
	if(is_subset)return t[p].v;
	push_down(p);
	return max(query(ls(p),l,r),query(rs(p),l,r));
}
ll f[maxn];
int st[maxn],tp;
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=n;++i)scanf("%d",b+i);
	build(1,0,n);
	for(ri i=1;i<=n;++i){
		modify(1,i-1,i-1,b[i]);
		while(tp&&a[i]<=a[st[tp]]){
			modify(1,st[tp-1],st[tp]-1,b[i]-b[st[tp]]);
			--tp;
		}
		f[i]=query(1,0,i-1);
		modify(1,i,i,f[i]);
		st[++tp]=i;
	}
	printf("%lld",f[n]);
	return 0;
}