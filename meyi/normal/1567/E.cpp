#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct node{
	int len,ls,lv,rs,rv;
	ll sum;
	inline node(int v=0):len(1),ls(1),lv(v),rs(1),rv(v),sum(1){}
	inline node operator+(const node &k)const{
		if(!len)return k;
		if(!k.len)return *this;
		node ret;
		ret.len=len+k.len;
		ret.ls=ls,ret.lv=lv;
		ret.rs=k.rs,ret.rv=k.rv;
		ret.sum=sum+k.sum;
		if(rv<=k.lv){
			if(ls==len)ret.ls=len+k.ls;
			if(k.rs==k.len)ret.rs=k.len+rs;
			ret.sum+=1ll*rs*k.ls;
		}
		return ret;
	}
}emp;
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
	t[p].l=l,t[p].r=r,t[p].v=0;
	if(l==r){
		t[p].v=node(a[l]);
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
void modify(int p,int k,int v){
	if(t[p].l>k||k>t[p].r)return;
	if(t[p].l==k&&k==t[p].r){
		t[p].v=node(v);
		return;
	}
	modify(ls(p),k,v);
	modify(rs(p),k,v);
	push_up(p);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
inline node query(int p,int l,int r){
	if(no_intersection)return emp;
	if(is_subset)return t[p].v;
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int m,n;
signed main(){
	emp.len=0;
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	build(1,1,n);
	while(m--){
		ri op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op&1)modify(1,x,y);
		else printf("%lld\n",query(1,x,y).sum);
	}
	return 0;
}