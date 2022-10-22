#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
struct segment_tree{
	int l,r,v,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=min(t[ls(p)].v,t[rs(p)].v);
}
int a[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].tag=0;
	if(l==r){
		t[p].v=a[l];
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,int v){
	t[p].v-=v,t[p].tag+=v;
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=0;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	if(is_subseg){
		add_tag(p,v);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
int query(int p,int l,int r){
	if(no_intersection)return INT_MAX;
	if(is_subseg)return t[p].v;
	push_down(p);
	return min(query(ls(p),l,r),query(rs(p),l,r));
}
int m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		build(1,1,n);
		for(ri i=1,pre=0;i<=n;++i){
			modify(1,i,i,i-1);
			modify(1,i-pre,n-pre,1);
			if(query(1,i-pre,n-pre)>=0){
				++pre;
				printf("1 ");
			}
			else{
				modify(1,i,i,1-i);
				modify(1,i-pre,n-pre,-1);
				printf("0 ");
			}
		}
		printf("\n");
	}
	return 0;
}