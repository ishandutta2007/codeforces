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
int a[maxn][5],k,n;
struct node{
	int mx,v[1<<5];
	inline node(int mx_=0){mx=mx_;memset(v,0,(1<<k)<<2);}
	inline node operator+(const node &rhs)const{
		if(mx==-1)return rhs;
		if(rhs.mx==-1)return *this;
		node ret;
		ret.mx=max(mx,rhs.mx);
		for(ri i=0;i<1<<k;++i){
			ckmax(ret.mx,v[i]+rhs.v[((1<<k)-1)^i]);
			ret.v[i]=max(v[i],rhs.v[i]);
		}
		return ret;
	}
};
struct segment_tree{
	int l,r;
	node v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=t[ls(p)].v+t[rs(p)].v;
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].v.mx=0;
		for(ri i=0;i<1<<k;++i){
			t[p].v.v[i]=0;
			for(ri j=0;j<k;++j){
				if(i&(1<<j))t[p].v.v[i]+=a[l][j];
				else t[p].v.v[i]-=a[l][j];
			}
		}
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
void modify(int p,int x){
	if(t[p].l>x||x>t[p].r)return;
	if(t[p].l==t[p].r){
		t[p].v.mx=0;
		for(ri i=0;i<1<<k;++i){
			t[p].v.v[i]=0;
			for(ri j=0;j<k;++j){
				if(i&(1<<j))t[p].v.v[i]+=a[x][j];
				else t[p].v.v[i]-=a[x][j];
			}
		}
		return;
	}
	modify(ls(p),x);
	modify(rs(p),x);
	push_up(p);
}
node query(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return {-1};
	if(l<=t[p].l&&t[p].r<=r)return t[p].v;
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int m;
int main(){
	n=qr(),k=qr();
	for(ri i=1;i<=n;++i)
		for(ri j=0;j<k;++j)
			a[i][j]=qr();
	build(1,1,n);
	m=qr();
	while(m--){
		ri op=qr();
		if(op&1){
			ri x=qr();
			for(ri i=0;i<k;++i)a[x][i]=qr();
			modify(1,x);
		}
		else{
			ri l=qr(),r=qr();
			qw(query(1,l,r).mx),putchar(10);
		}
	}
	return 0;
}