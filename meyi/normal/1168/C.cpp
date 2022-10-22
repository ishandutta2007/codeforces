#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=3e5+10;
struct node{
	int a[19];
	inline node(int _=0){memset(a,0,sizeof a);a[0]=_;}
	inline int& operator[](int id){return a[id];}
	inline node operator+(node k){
		if(a[0]==-1)return k;
		if(k[0]==-1)return *this;
		node ret;
		for(ri i=0;i<19;++i){
			ret[i]=a[i];
			for(ri j=0;j<19;++j)
				if(a[i]&(1<<j))
					ret[i]|=k[j];
		}
		return ret;
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
		for(ri i=0;i<19;++i){
			if(a[l]&(1<<i))t[p].v[i]=a[l];
			t[p].v[i]|=(1<<i);
		}
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
node query(int p,int l,int r){
	if(no_intersection)return node(-1);
	if(is_subset)return t[p].v;
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	build(1,1,n);
	while(q--){
		ri l,r;
		scanf("%d%d",&l,&r);
		ri x=0;
		node y=query(1,l+1,r);
		for(ri i=0;i<19;++i)
			if(a[l]&(1<<i))
				x|=y[i];
		puts((x&a[r])?"Shi":"Fou");
	}
	return 0;
}