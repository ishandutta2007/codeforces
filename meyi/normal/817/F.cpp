#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct segment_tree{
	int l,r,sum,tag1;
	bool tag2;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].sum=t[ls(p)].sum+t[rs(p)].sum;
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].tag1=-1;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag1(int p,bool v){
	t[p].sum=(v?t[p].r-t[p].l+1:0);
	t[p].tag1=v,t[p].tag2=0;
}
inline void add_tag2(int p){
	t[p].sum=t[p].r-t[p].l+1-t[p].sum;
	t[p].tag2^=1;
}
inline void push_down(int p){
	if(t[p].tag1!=-1){
		add_tag1(ls(p),t[p].tag1);
		add_tag1(rs(p),t[p].tag1);
		t[p].tag1=-1;
	}
	if(t[p].tag2){
		add_tag2(ls(p));
		add_tag2(rs(p));
		t[p].tag2=0;
	}
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify1(int p,int l,int r,bool v){
	if(no_intersection)return;
	if(is_subset){
		add_tag1(p,v);
		return;
	}
	push_down(p);
	modify1(ls(p),l,r,v);
	modify1(rs(p),l,r,v);
	push_up(p);
}
void modify2(int p,int l,int r){
	if(no_intersection)return;
	if(is_subset){
		add_tag2(p);
		return;
	}
	push_down(p);
	modify2(ls(p),l,r);
	modify2(rs(p),l,r);
	push_up(p);
}
inline int query(int p){
	if(t[p].l==t[p].r)return t[p].l;
	push_down(p);
	if(t[ls(p)].r-t[ls(p)].l+1>t[ls(p)].sum)return query(ls(p));
	else return query(rs(p));	
}
struct node{int op;ll l,r;}a[maxn];
ll b[maxn];
int bl,n;
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d%lld%lld",&a[i].op,&a[i].l,&a[i].r);
		b[++bl]=a[i].l,b[++bl]=a[i].r,b[++bl]=a[i].r+1;
	}
	b[++bl]=1;
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	build(1,1,bl);
	for(ri i=1;i<=n;++i){
		a[i].l=lower_bound(b+1,b+bl+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+bl+1,a[i].r)-b;
		if(a[i].op<3)modify1(1,a[i].l,a[i].r,2-a[i].op);
		else modify2(1,a[i].l,a[i].r);
		printf("%lld\n",b[query(1)]);
	}
	return 0;
}