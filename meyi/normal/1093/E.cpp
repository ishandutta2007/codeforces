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
struct segment_tree{
	int ls,rs,sum;
}t[maxn*200];
int cnt,st[maxn],tp;
#define new_node (tp?st[tp--]:++cnt)
void insert(int &p,int l,int r,int k,int v){
	if(!p)p=new_node;
	t[p].sum+=v;
	if(l==r)return;
	ri mid=l+r>>1;
	if(k<=mid)insert(t[p].ls,l,mid,k,v);
	else insert(t[p].rs,mid+1,r,k,v);
	if(!t[p].sum)st[++tp]=p,p=0;
}
int query(int p,int l,int r,int ql,int qr){
	if(!p)return 0;
	if(ql<=l&&r<=qr)return t[p].sum;
	ri mid=l+r>>1,ret=0;
	if(ql<=mid)ret+=query(t[p].ls,l,mid,ql,qr);
	if(qr>mid)ret+=query(t[p].rs,mid+1,r,ql,qr);
	return ret;
}
int n,rt[maxn];
#define lowbit(k) (k&-k)
inline void modify(int k1,int k2,int k3){
	for(;k1<=n;k1+=lowbit(k1)){
		if(k2)insert(rt[k1],1,n,k2,-1);
		insert(rt[k1],1,n,k3,1);
	}
}
inline int query(int l1,int r1,int l2,int r2){
	ri ret=0;
	for(;r1;r1^=lowbit(r1))ret+=query(rt[r1],1,n,l2,r2);
	for(--l1;l1;l1^=lowbit(l1))ret-=query(rt[l1],1,n,l2,r2);
	return ret;
}
int a[maxn],b[maxn],m,posa[maxn],posb[maxn];
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i)posa[a[i]=qr()]=i;
	for(ri i=1;i<=n;++i)posb[b[i]=qr()]=i;
	for(ri i=1;i<=n;++i)modify(i,0,posb[a[i]]);
	while(m--){
		ri op=qr();
		if(op&1){
			ri l1=qr(),r1=qr(),l2=qr(),r2=qr();
			qw(query(l1,r1,l2,r2)),putchar(10);
		}
		else{
			ri x=qr(),y=qr();
			modify(posa[b[x]],x,y);
			modify(posa[b[y]],y,x);
			swap(posb[b[x]],posb[b[y]]);
			swap(b[x],b[y]);
		}
	}
	return 0;
}