#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
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
int a[maxn],n,q;
ll pre[maxn];
struct segment_tree{
	int l,r;
	ll mx,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].mx=pre[r]-pre[l-1]*2;
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,ll v){
	t[p].mx+=v,t[p].tag+=v;
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
bool query(int p){
	if(t[p].l==t[p].r){
		if(!t[p].mx){
			qw(t[p].l);
			return true;
		}
		return false;
	}
	push_down(p);
	return (t[ls(p)].mx>=0&&query(ls(p)))||(t[rs(p)].mx>=0&&query(rs(p)));
}
int main(){
	n=qr(),q=qr();
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		pre[i]=pre[i-1]+a[i];
	}
	build(1,1,n);
	while(q--){
		ri x=qr(),y=qr();
		modify(1,x,x,y-a[x]);
		if(x<n)modify(1,x+1,n,a[x]-y);
		a[x]=y;
		if(!query(1))putchar('-'),putchar('1');
		putchar(10);
	}
	return 0;
}