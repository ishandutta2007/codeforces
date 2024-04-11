#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;bool f=false;char ch;
	while(!isdigit(ch=getchar()))f|=(ch=='-');
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return f?-in:in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
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
int ans,m,n,pos;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>q1[maxn],q2[maxn];
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i)a[i]=qr();
	for(ri i=1;i<=m;++i){
		ri x=qr(),y=qr();
		q1[y].emplace_back(x,i),q2[x].emplace_back(y,i);
	}
	build(1,1,n);
	for(ri i=1;i<=n;++i){
		if(i>1){
			ri tmp=a[i]-query(1,1,i-1);
			if(tmp>ans)ans=tmp,pos=i;
		}
		for(const pii &j:q1[i])modify(1,j.fi,i,1);
	}
	build(1,1,n);
	for(ri i=n;i;--i){
		if(i<n){
			ri tmp=a[i]-query(1,i+1,n);
			if(tmp>ans)ans=tmp,pos=-i;
		}
		for(const pii &j:q2[i])modify(1,i,j.fi,1);
	}
	vector<int>id;
	if(pos<0){
		for(ri i=n;i>-pos;--i)
			for(const pii &j:q2[i])
				id.push_back(j.se);
	}
	else{
		for(ri i=1;i<pos;++i)
			for(const pii &j:q1[i])
				id.push_back(j.se);
	}
	qw(ans),putchar(10),qw(id.size()),putchar(10);
	for(ri i:id)qw(i),putchar(32);
	return 0;
}