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
    int l,r;
    ll f[2][2];
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	for(ri i:{0,1})
		for(ri j:{0,1}){
			t[p].f[i][j]=max(t[ls(p)].f[i][j],t[rs(p)].f[i][j]);
			for(ri k:{0,1})ckmax(t[p].f[i][j],t[ls(p)].f[i][k]+t[rs(p)].f[k^1][j]);
		}
}
int a[maxn];
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){
		t[p].f[0][0]=a[l],t[p].f[1][1]=-a[l];
		t[p].f[0][1]=t[p].f[1][0]=LLONG_MIN/2;
        return;
    }
    ri mid=l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);
}
void modify(int p,int k){
    if(t[p].l>k||k>t[p].r)return;
    if(t[p].l==t[p].r){
        t[p].f[0][0]=a[k],t[p].f[1][1]=-a[k];
        return;
    }
    modify(ls(p),k);
    modify(rs(p),k);
    push_up(p);
}
int m,n,t_case;
signed main(){
	t_case=qr();
	while(t_case--){
		n=qr(),m=qr();
		for(ri i=1;i<=n;++i)a[i]=qr();
		build(1,1,n);
		qw(max(t[1].f[0][0],t[1].f[0][1])),putchar(10);
		while(m--){
			ri l=qr(),r=qr();
			swap(a[l],a[r]);
			modify(1,l),modify(1,r);
			qw(max(t[1].f[0][0],t[1].f[0][1])),putchar(10);
		}
	}
	return 0;
}