#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],aa[maxn],m,n;
struct SGT{
	struct segment_tree{
		int l,r,v;
		bool tag;
	}t[maxn<<2];
	#define ls(p) (p<<1)
	#define rs(p) (p<<1|1)
	inline void push_up(int p){
		t[p].v=t[ls(p)].v+t[rs(p)].v;
	}
	void build(int p,int l,int r){
		t[p].l=l,t[p].r=r,t[p].v=0;
		if(l==r){
			t[p].v=a[l];
			return;
		}
		ri mid=l+r>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		push_up(p);
	}
	inline void add_tag(int p){
		t[p].v=(t[p].r-t[p].l+1)-t[p].v;
		t[p].tag^=1;
	}
	inline void push_down(int p){
		if(!t[p].tag)return;
		add_tag(ls(p));
		add_tag(rs(p));
		t[p].tag=0;
	}
	#define no_intersection (t[p].l>r||l>t[p].r)
	#define is_subset (l<=t[p].l&&t[p].r<=r)
	void modify(int p,int l,int r){
		if(no_intersection)return;
		if(is_subset){
			add_tag(p);
			return;
		}
		push_down(p);
		modify(ls(p),l,r);
		modify(rs(p),l,r);
		push_up(p);
	}
	inline int query(int p,int l,int r){
		if(no_intersection)return 0;
		if(is_subset)return t[p].v;
		push_down(p);
		return query(ls(p),l,r)+query(rs(p),l,r);
	}
}t[20];
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",aa+i);
	for(ri i=0;i<20;++i){
		for(ri j=1;j<=n;++j)a[j]=(aa[j]>>i)&1;
		t[i].build(1,1,n);
	}
	scanf("%d",&m);
	while(m--){
		ri op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op&1){
			ll sum=0;
			for(ri i=0;i<20;++i)sum+=(1ll<<i)*t[i].query(1,x,y);
			printf("%lld\n",sum);
		}
		else{
			scanf("%d",&z);
			for(ri i=0;i<20;++i)
				if(z&(1<<i))
					t[i].modify(1,x,y);
		}
	}
	return 0;
}