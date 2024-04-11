#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct segment_tree{
	int l,r;
	set<int>s;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	t[p].s.insert(v);
	if(is_subset)return;
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
}
int query(int p,int l,int r,int v){
	if(no_intersection)return INT_MAX;
	if(is_subset){
		auto it=t[p].s.lower_bound(v);
		return it==t[p].s.end()?INT_MAX:*it;
	}
	return min(query(ls(p),l,r,v),query(rs(p),l,r,v));
}
int a[maxn],m,n,t_case;
set<int>s;
int main(){
	scanf("%d%d",&n,&m);
	s.insert(0);
	for(ri i=1;i<=n;++i)s.insert(i);
	s.insert(n+1);
	build(1,1,n);
	while(m--){
		ri op,x,y,z;
		scanf("%d%d",&op,&x);
		if(op){
			auto it=s.find(x);
			if(it!=s.end()){
				ri l=*prev(it)+1,r=*next(it)-1;
				if(query(1,l,x,x)<=r)puts("YES");
				else puts("N/A");
			}
			else puts("NO");
		}
		else{
			scanf("%d%d",&y,&z);
			if(z)modify(1,x,x,y);
			else{
				auto it=s.lower_bound(x);
				while(it!=s.end()&&*it<=y)it=s.erase(it);
			}
		}
	}
	return 0;
}