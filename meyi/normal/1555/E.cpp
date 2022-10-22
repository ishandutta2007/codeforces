#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
#define ls(k) (k<<1)
#define rs(k) (k<<1|1)
typedef long long ll;
const int maxn=3e6+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct segment_tree{
	int l,r,tag,v;
}t[maxn<<2];
inline void push_up(int k){
	t[k].v=min(t[ls(k)].v,t[rs(k)].v);
}
inline void add_tag(int k,int v){
	t[k].v+=v;
	t[k].tag+=v;
}
inline void push_down(int k){
	if(!t[k].tag)return;
	add_tag(ls(k),t[k].tag);
	add_tag(rs(k),t[k].tag);
	t[k].tag=0;
}
void build(int k,int l,int r){
	t[k].l=l,t[k].r=r,t[k].tag=t[k].v=0;
	if(l==r)return;
	int mid=l+r>>1;
	build(ls(k),l,mid);
	build(rs(k),mid+1,r);
}
void add(int k,int l,int r,int v){
	if(l>t[k].r||t[k].l>r)return;
	if(l<=t[k].l&&t[k].r<=r){
		add_tag(k,v);
		return;
	}
	push_down(k);
	add(ls(k),l,r,v);
	add(rs(k),l,r,v);
	push_up(k);
}
int query(int k,int l,int r){
	if(l>t[k].r||t[k].l>r)return INT_MAX;
	if(l<=t[k].l&&t[k].r<=r)return t[k].v;
	push_down(k);
	return min(query(ls(k),l,r),query(rs(k),l,r));
}
int ans=INT_MAX,m,n;
struct node{
	int l,r,v;
	inline bool operator<(const node &k)const{
		return v<k.v;
	}
}a[maxn];
signed main(){
	n=qr(),m=qr()*2-1;
	for(ri i=1;i<=n;++i)a[i].l=qr()*2-1,a[i].r=qr()*2-1,a[i].v=qr();
	sort(a+1,a+n+1);
	build(1,1,m);
	for(ri i=1,lst=1;i<=n;++i){
		add(1,a[i].l,a[i].r,1);
		while(query(1,a[lst].l,a[lst].r)>1)add(1,a[lst].l,a[lst].r,-1),++lst;
		if(t[1].v)ckmin(ans,a[i].v-a[lst].v);
	}
	qw(ans);
	return 0;
}