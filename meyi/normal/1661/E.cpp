#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxm=4,maxn=5e5+10;
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
inline int gc(){
	char ch;
	while(!isdigit(ch=getchar()));
	return ch^48;
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[maxm][maxn],fa[maxm*maxn],m,n,tot;
int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
inline bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){fa[x]=y;return true;}
	return false;
}
struct node{
	int cnt,dos,l[maxm],pos,r[maxm];
	inline node(){dos=pos=0;}
	inline node operator+(const node &k)const{
		if(!pos)return k;
		if(!k.pos)return *this;
		for(ri i=1;i<=m;++i){
			if(a[i][dos])fa[l[i]]=l[i];
			if(a[i][pos])fa[r[i]]=r[i];
			if(a[i][k.dos])fa[k.l[i]]=k.l[i];
			if(a[i][k.pos])fa[k.r[i]]=k.r[i];
		}
		node ret;
		ret.cnt=cnt+k.cnt;
		for(ri i=1;i<=m;++i)
			if(a[i][pos]&&a[i][pos+1])
				ret.cnt-=merge(r[i],k.l[i]);
		for(ri i=1;i<=m;++i){
			if(a[i][dos])ret.l[i]=find(l[i]);
			if(a[i][k.pos])ret.r[i]=find(k.r[i]);
		}
		ret.dos=dos,ret.pos=k.pos;
		return ret;
	}
};
struct segment_tree{
	int l,r;
	node v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].v.cnt=0,t[p].v.dos=l,t[p].v.pos=r;
		for(ri i=1;i<=m;++i)
			if(a[i][l]){
				if(a[i-1][l]!=1)++t[p].v.cnt,++tot;
				t[p].v.l[i]=t[p].v.r[i]=tot;
			}
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].v=t[ls(p)].v+t[rs(p)].v;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
node query(int p,int l,int r){
	if(no_intersection)return node();
	if(is_subseg)return t[p].v;
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int q;
int main(){
	m=3,n=qr();
	clear(a[0],n,-1);
	for(ri i=1;i<=m;++i)
		for(ri j=1;j<=n;++j)
			a[i][j]=gc();
	build(1,1,n);
	q=qr();
	while(q--){
		ri l=qr(),r=qr();
		qw(query(1,l,r).cnt),putchar(10);
	}
	return 0;
}