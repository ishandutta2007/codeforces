#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct node{
	int val[26];
	inline void clear(){
		memset(val,0,sizeof val);
	}
	inline node(){
		clear();
	}
	inline int& operator[](const int &id){
		return val[id];	
	}
	inline node operator+(const node &k){
		node ret;
		for(ri i=0;i<26;++i)ret.val[i]=val[i]+k.val[i];
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
		++t[p].v[s[l]];
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,int v){
	t[p].v.clear();
	t[p].v[v]=t[p].r-t[p].l+1;
	t[p].tag=v;
}
inline void push_down(int p){
	if(t[p].tag==-1)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=-1;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	if(is_subset){
		add_tag(p,v);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
inline node query(int p,int l,int r){
	if(no_intersection)return node();
	if(is_subset)return t[p].v;
	push_down(p);
	return query(ls(p),l,r)+query(rs(p),l,r);
}
void print(int p){
	if(t[p].l!=t[p].r){
		push_down(p);
		print(ls(p));
		print(rs(p));
	}
	else{
		for(ri i=0;i<26;++i)
			if(t[p].v[i]){
				putchar(i+'a');
				break;
			}
	}
}
int m,n;
signed main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(ri i=1;i<=n;++i)s[i]-='a';
	build(1,1,n);
	while(m--){
		ri l,r;
		scanf("%d%d",&l,&r);
		if((r-l)&1){
			node tmp=query(1,l,r);
			ri pos=-1;
			for(ri i=0;i<26;++i)
				if(tmp[i]&1){
					pos=i;
					break;
				}
			if(pos==-1){
				ri sum=0;
				for(ri i=0;i<26;++i)
					if(tmp[i]){
						modify(1,l+sum,l+sum+(tmp[i]>>1)-1,i);
						modify(1,r-sum-(tmp[i]>>1)+1,r-sum,i);
						sum+=(tmp[i]>>1);
					}
			}
		}
		else{
			node tmp=query(1,l,r);
			ri pos=-1;
			for(ri i=0;i<26;++i)
				if(tmp[i]&1){
					if(pos>=0){
						pos=-2;
						break;
					}
					else pos=i;
				}
			if(pos>=0){
				ri sum=0;
				for(ri i=0;i<26;++i)
					if(tmp[i]>1){
						modify(1,l+sum,l+sum+(tmp[i]>>1)-1,i);
						modify(1,r-sum-(tmp[i]>>1)+1,r-sum,i);
						sum+=(tmp[i]>>1);
					}
				modify(1,l+sum,r-sum,pos);
			}
		}
	}
	print(1);
	return 0;
}