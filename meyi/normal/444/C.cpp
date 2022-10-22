#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct segment_tree{
    int l,r,c;
    bool s;
    ll v,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	if(t[ls(p)].s&&t[rs(p)].s&&t[ls(p)].c==t[rs(p)].c){
		t[p].c=t[ls(p)].c;
		t[p].s=true;
	}
	else t[p].s=false;
	t[p].v=t[ls(p)].v+t[rs(p)].v;
}
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){
    	t[p].c=l;
		t[p].s=true;
        return;
    }
    ri mid=l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);
}
inline void add_tag(int p,int v1,ll v2){
	t[p].v+=v2*(t[p].r-t[p].l+1);
	t[p].c=v1;
	t[p].tag+=v2;
}
inline void push_down(int p){
    if(!t[p].tag)return;
    add_tag(ls(p),t[p].c,t[p].tag);
    add_tag(rs(p),t[p].c,t[p].tag);
    t[p].tag=0;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
    if(no_intersection)return;
    if(is_subset&&t[p].s){
        add_tag(p,v,abs(t[p].c-v));
        return;
    }
    push_down(p);
    modify(ls(p),l,r,v);
    modify(rs(p),l,r,v);
    push_up(p);
}
inline ll query(int p,int l,int r){
    if(no_intersection)return 0;
    if(is_subset)return t[p].v;
    push_down(p);
    return query(ls(p),l,r)+query(rs(p),l,r);
}
int m,n;
signed main(){
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--){
		ri op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op&1){
			scanf("%d",&z);
			modify(1,x,y,z);
		}
		else printf("%lld\n",query(1,x,y));
	}
	return 0;
}