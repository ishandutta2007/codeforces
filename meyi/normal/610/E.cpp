#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int k,m,n;
struct node{
	int pre,suf,v[10][10];
	inline node(int c=0){
		pre=suf=c;
		for(ri i=0;i<k;++i)memset(v[i],0,k<<2);
	}
	inline node operator+(const node &rhs)const{
		node ret;
		ret.pre=pre,ret.suf=rhs.suf;
		for(ri i=0;i<k;++i)
			for(ri j=0;j<k;++j)
				ret.v[i][j]=v[i][j]+rhs.v[i][j];
		++ret.v[suf][rhs.pre];
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
		t[p].v=node(s[l]-'a');
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,int v){
	t[p].v=node(v);
	t[p].v.v[v][v]=t[p].r-t[p].l;
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
char ss[21];
int main(){
	scanf("%d%d%d%s",&n,&m,&k,s+1);
	build(1,1,n);
	while(m--){
		ri op;
		scanf("%d",&op);
		if(op&1){
			ri l,r;
			scanf("%d%d",&l,&r);
			char c=getchar();
			while(!islower(c))c=getchar();
			modify(1,l,r,c-'a');
		}
		else{
			scanf("%s",ss+1);
			ri ans=0;
			for(ri i=1;i<=k;++i){
				ss[i]-='a';
				if(t[1].v.pre==ss[i])ans+=i-1;
				if(t[1].v.suf==ss[i])ans+=k-i;
				for(ri j=1;j<=i;++j){
					if(j<i)ans+=(i-j-1)*t[1].v.v[ss[j]][ss[i]];
					ans+=(j+k-i-1)*t[1].v.v[ss[i]][ss[j]];
				}
			}
			printf("%d\n",(ans+n)/k);
		}
	}
	return 0;
}