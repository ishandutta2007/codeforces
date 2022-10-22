#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=3e5+10;
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
	int l,r;
	ll v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].v=LLONG_MAX;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
void modify(int p,int k,ll v){
	while(t[p].l!=t[p].r)p=(k<=t[ls(p)].r?ls(p):rs(p));
	ckmin(t[p].v,v);
	while(p>>=1)t[p].v=min(t[ls(p)].v,t[rs(p)].v);
}
ll query(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return LLONG_MAX;
	if(l<=t[p].l&&t[p].r<=r)return t[p].v;
	return min(query(ls(p),l,r),query(rs(p),l,r));
}
ll ans[maxn];
int id[maxn],l[maxn],m,n,r[maxn],st[maxn],tp,w[maxn],x[maxn];
signed main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i)x[i]=qr(),w[i]=qr();
	for(ri i=1;i<=m;++i)id[i]=i,l[i]=qr(),r[i]=qr();
	sort(id+1,id+m+1,[&](int x,int y){return r[x]<r[y];});
	build(1,1,n);
	for(ri i=1,j=1;i<=n;++i){
		while(tp&&w[i]<=w[st[tp]]){
			modify(1,st[tp],1ll*(x[i]-x[st[tp]])*(w[i]+w[st[tp]]));
			--tp;
		}
		if(tp)modify(1,st[tp],1ll*(x[i]-x[st[tp]])*(w[i]+w[st[tp]]));
		st[++tp]=i;
		while(j<=m&&r[id[j]]==i)ans[id[j]]=query(1,l[id[j]],i-1),++j;
	}
	for(ri i=1;i<=m;++i)qw(ans[i]),putchar(10);
	return 0;
}