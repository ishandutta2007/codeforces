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
int k,lg,lg2[maxn],n,q,st[(int)log2(maxn)+1][maxn];
inline void build_st(){
	for(ri i=1;i<=n;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i),st[0][i]=qr();
	lg=lg2[n];
	for(ri i=1;i<=lg;++i)
		for(ri j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
inline int query(int l,int r){
	if(r-l+1>n)return query(1,n);
	l=(l-1)%n+1,r=(r-1)%n+1;
	if(r<l)return min(query(1,r),query(l,n));
	ri k=lg2[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
struct segment_tree{
	int ls,rs,mn,tag;
}t[maxn<<7];
int cnt;
void modify(int &p,int l,int r,int ql,int qr,int v,int tag){
	if(!p)p=++cnt,t[p].mn=query(l,r);
	if(tag)t[p].mn=t[p].tag=tag;
	if(l>qr||ql>r)return;
	if(ql<=l&&r<=qr){
		t[p].mn=t[p].tag=v;
		return;
	}
	ri mid=l+r>>1;
	modify(t[p].ls,l,mid,ql,qr,v,t[p].tag);
	modify(t[p].rs,mid+1,r,ql,qr,v,t[p].tag);
	t[p].mn=min(t[t[p].ls].mn,t[t[p].rs].mn),t[p].tag=0;
}
int query(int &p,int l,int r,int ql,int qr,int tag){
	if(!p)p=++cnt,t[p].mn=query(l,r);
	if(tag)t[p].mn=t[p].tag=tag;
	if(l>qr||ql>r)return INT_MAX;
	if(ql<=l&&r<=qr)return t[p].mn;
	ri mid=l+r>>1,ret=INT_MAX;
	ckmin(ret,query(t[p].ls,l,mid,ql,qr,t[p].tag));
	ckmin(ret,query(t[p].rs,mid+1,r,ql,qr,t[p].tag));
	t[p].tag=0;
	return ret;
}
int rt;
int main(){
	n=qr(),k=qr();
	build_st();
	k*=n;
	q=qr();
	t[0].mn=INT_MAX;
	while(q--){
		ri op=qr(),x=qr(),y=qr();
		if(op&1)modify(rt,1,k,x,y,qr(),0);
		else qw(query(rt,1,k,x,y,0)),putchar(10);
	}
	return 0;
}