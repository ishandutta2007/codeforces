#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxm=11,maxn=1e5+10;
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
int a[maxm][maxn],m,n;
struct node{
	int cnt,mx,l[maxm],pos,r[maxm];
	inline node(){pos=0;}
	inline node operator+(const node &k)const{
		if(!pos)return k;
		if(!k.pos)return *this;
		vector<int>fa(mx+k.mx+1);
		iota(fa.begin(),fa.end(),0);
		function<int(int)>find=[&](int k){return k==fa[k]?k:fa[k]=find(fa[k]);};
		auto merge=[&](int x,int y){
			if(x>y)swap(x,y);
			ri fx=find(x),fy=find(y);
			if(fx!=fy){fa[fy]=fx;return true;}
			return false;
		};
		node ret;
		ret.cnt=cnt+k.cnt;
		for(ri i=1;i<=m;++i)
			if(a[i][pos]==a[i][pos+1])
				ret.cnt-=merge(r[i],k.l[i]+mx);
		vector<int>id(fa.size());
		ret.mx=0;
		for(ri i=1;i<=m;++i){
			ret.l[i]=find(l[i]);
			if(!id[ret.l[i]])id[ret.l[i]]=++ret.mx;
			ret.l[i]=id[ret.l[i]];
			ret.r[i]=find(k.r[i]+mx);
			if(!id[ret.r[i]])id[ret.r[i]]=++ret.mx;
			ret.r[i]=id[ret.r[i]];
		}
		ret.pos=k.pos;
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
		t[p].v.cnt=0,t[p].v.pos=l;
		for(ri i=1;i<=m;++i){
			if(a[i][l]!=a[i-1][l])++t[p].v.cnt;
			t[p].v.l[i]=t[p].v.r[i]=t[p].v.cnt;
		}
		t[p].v.mx=t[p].v.cnt;
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
	m=qr(),n=qr(),q=qr();
	for(ri i=1;i<=m;++i)
		for(ri j=1;j<=n;++j)
			a[i][j]=qr();
	build(1,1,n);
	while(q--){
		ri l=qr(),r=qr();
		qw(query(1,l,r).cnt),putchar(10);
	}
	return 0;
}