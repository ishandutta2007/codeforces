#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=3e5+10,maxv=1e6+10;
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
inline char gc(){
	char ch=getchar();
	while(ch!='+'&&ch!='-'&&ch!='?')ch=getchar();
	return ch;
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
ll ans,lst[maxv<<2],sum[maxv<<2];
void build(int p,int l,int r){
	lst[p]=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void modify(int p,int l,int r,int k,int v){
	if(l==r){
		lst[p]+=v;
		sum[p]+=v;
		return;
	}
	ri mid=l+r>>1;
	k<=mid?modify(p<<1,l,mid,k,v):modify(p<<1|1,mid+1,r,k,v);
	lst[p]=max(lst[p<<1]+sum[p<<1|1],lst[p<<1|1]);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
void query(int p,int l,int r,int k){
	if(r<=k){
		ans=max(ans+sum[p],lst[p]);
		return;
	}
	ri mid=l+r>>1;
	query(p<<1,l,mid,k);
	if(k>mid)query(p<<1|1,mid+1,r,k);
}
int q,x[maxn],y[maxn];
int main(){
	build(1,1,1000000);
	q=qr();
	for(ri i=1;i<=q;++i){
		char op=gc();
		x[i]=qr();
		if(op=='+')y[i]=qr(),modify(1,1,1000000,x[i],y[i]);
		if(op=='-')modify(1,1,1000000,x[x[i]],-y[x[i]]);
		if(op=='?'){
			ans=0;
			query(1,1,1000000,x[i]);
			qw(ans-x[i]),putchar(10);
		}
	}
	return 0;
}