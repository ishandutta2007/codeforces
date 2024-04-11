#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mx=1e9;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct SGT{
	int ls,rs,mn,mx,tag;
}t[maxn<<6];
int cnt,rt;
inline void build(int &p,int l,int r){
	if(p)return;
	p=++cnt;
	t[p].mn=l,t[p].mx=r,t[p].tag=0; 
} 
inline void push_up(int p){
	t[p].mn=min(t[t[p].ls].mn,t[t[p].rs].mn);
	t[p].mx=max(t[t[p].ls].mx,t[t[p].rs].mx);
}
inline void add_tag(int p,int v){
	t[p].mn+=v,t[p].mx+=v,t[p].tag+=v;
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(t[p].ls,t[p].tag);
	add_tag(t[p].rs,t[p].tag);
	t[p].tag=0;
}
void modify(int p,int l,int r,int ql,int qr,int v){
	if(ql>r||l>qr)return;
	if(ql<=l&&r<=qr){
		add_tag(p,v);
		return;
	}
	ri mid=l+r>>1;
	build(t[p].ls,l,mid),build(t[p].rs,mid+1,r);
	push_down(p);
	modify(t[p].ls,l,mid,ql,qr,v),modify(t[p].rs,mid+1,r,ql,qr,v);
	push_up(p);
}
int query_l(int p,int l,int r,int v){
	if(l==r)return r;
	ri mid=l+r>>1;
	build(t[p].ls,l,mid),build(t[p].rs,mid+1,r);
	push_down(p);
	if(t[t[p].rs].mn<=v)return query_l(t[p].rs,mid+1,r,v);
	else return query_l(t[p].ls,l,mid,v);
}
int query_r(int p,int l,int r,int v){
	if(l==r)return l;
	ri mid=l+r>>1;
	build(t[p].ls,l,mid),build(t[p].rs,mid+1,r);
	push_down(p);
	if(t[t[p].ls].mx>=v)return query_r(t[p].ls,l,mid,v);
	else return query_r(t[p].rs,mid+1,r,v);
}
int query(int p,int l,int r,int k){
	if(l>k||k>r)return 0;
	if(l==r)return t[p].mx;
	ri mid=l+r>>1;
	build(t[p].ls,l,mid),build(t[p].rs,mid+1,r);
	push_down(p);
	return query(t[p].ls,l,mid,k)+query(t[p].rs,mid+1,r,k);
}
int lst,n;
signed main(){
	scanf("%d",&n);
	build(rt,0,mx);
	while(n--){
		ri t;
		scanf("%d",&t);
		if(t>0&&::t[rt].mn<t)modify(rt,0,mx,0,query_l(rt,0,mx,t-1),1);
		if(t<mx&&::t[rt].mx>t)modify(rt,0,mx,query_r(rt,0,mx,t+1),mx,-1);
		ri k;
		scanf("%d",&k);
		while(k--){
			ri x;
			scanf("%d",&x);
			x=(x+lst)%(mx+1);
			printf("%d\n",lst=query(rt,0,mx,x));
		}
	}
	return 0;
}