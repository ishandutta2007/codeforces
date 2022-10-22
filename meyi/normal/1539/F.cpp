#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int n;
struct segment_tree{
	int l,r;
	int mn,mx;
	int tag;
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
inline void push_down(int p){
	if(!t[p].tag)return;
	ri tmp=ls(p);
	t[tmp].mn+=t[p].tag;
	t[tmp].mx+=t[p].tag;
	t[tmp].tag+=t[p].tag;
	tmp=rs(p);
	t[tmp].mn+=t[p].tag;
	t[tmp].mx+=t[p].tag;
	t[tmp].tag+=t[p].tag;
	t[p].tag=0;
}
inline void push_up(int p){
	t[p].mn=min(t[ls(p)].mn,t[rs(p)].mn);
	t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
}
void modify(int p,int l,int r,int v){
	if(l>t[p].r||t[p].l>r)return;
	if(l<=t[p].l&&t[p].r<=r){
		t[p].mn+=v;
		t[p].mx+=v;
		t[p].tag+=v;
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
int query_mn(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return INT_MAX;
	if(l<=t[p].l&&t[p].r<=r)return t[p].mn;
	push_down(p);
	return min(query_mn(ls(p),l,r),query_mn(rs(p),l,r));
}
int query_mx(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return INT_MIN;
	if(l<=t[p].l&&t[p].r<=r)return t[p].mx;
	push_down(p);
	return max(query_mx(ls(p),l,r),query_mx(rs(p),l,r));
}
int a[maxn];
inline void change(int k,int v){
	modify(1,k,n,v-a[k]);
	a[k]=v;
}
vector<int>pos[maxn];
int ans[maxn];
int main(){
	scanf("%d",&n);
	build(1,1,n);
	for(ri i=1,x;i<=n;++i){
		scanf("%d",&x),pos[x].push_back(i);
		change(i,1);
	}
	for(ri i=1;i<200001;++i){
		for(auto j:pos[i]){
			change(j,0);
			ri mn=min(query_mn(1,1,j-1),0),mx=query_mx(1,j,n);
			ckmax(ans[j],mx-mn+1);
			change(j,1);
		}
		for(auto j:pos[i])change(j,-1);
		for(auto j:pos[i]){
			change(j,0);
			ri mx=max(query_mx(1,1,j-1),0),mn=query_mn(1,j,n);
			ckmax(ans[j],-(mn-mx));
			change(j,-1);
		}
	}
	for(ri i=1;i<=n;++i)printf("%d ",ans[i]/2);
	return 0;
}