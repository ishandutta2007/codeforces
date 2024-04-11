#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
typedef pair<int,int> pii;
#define fi first
#define se second
struct node{
	int a[26];
	inline node(int x=0,int y=0){memset(a,0,sizeof a);a[x]=y;}
	inline node operator+(const node &k)const{
		node ret;
		for(ri i=0;i<26;++i)ret.a[i]=a[i]+k.a[i];
		return ret;
	}
};
struct segment_tree{
	int l,r,tag;
	node v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=t[ls(p)].v+t[rs(p)].v;
}
char s[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].tag=-1;
	if(l==r){
		t[p].v.a[s[l]-'a']=1;
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,int v){
	t[p].v=node(v,t[p].r-t[p].l+1);
	t[p].tag=v;
}
inline void push_down(int p){
	if(t[p].tag==-1)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=-1;
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
node query(int p,int l,int r){
	if(no_intersection)return node();
	if(is_subseg)return t[p].v;
	push_down(p);
	return query(ls(p),l,r)+query(rs(p),l,r);
}
inline void output(int p){
	if(t[p].l==t[p].r){
		for(ri i=0;i<26;++i)
			if(t[p].v.a[i])
				putchar(i+'a');
		return;
	}
	push_down(p);
	output(ls(p)),output(rs(p));
}
int m,n;
signed main(){
	scanf("%d%d%s",&n,&m,s+1);
	build(1,1,n);
	while(m--){
		ri x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ri pos=x;
		node tmp=query(1,x,y);
		if(z){
			for(ri i=0;i<26;++i)
				if(tmp.a[i])
					modify(1,pos,pos+tmp.a[i]-1,i),pos+=tmp.a[i];
		}
		else{
			for(ri i=25;~i;--i)
				if(tmp.a[i])
					modify(1,pos,pos+tmp.a[i]-1,i),pos+=tmp.a[i];
		}
	}
	output(1);
	return 0;
}