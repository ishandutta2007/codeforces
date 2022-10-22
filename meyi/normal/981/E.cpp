#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e4+1;
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
vector<int>a[maxn<<2];
bitset<maxn>ans;
void insert(int p,int l,int r,int ql,int qr,int v){
	if(ql<=l&&r<=qr){a[p].push_back(v);return;}
	ri mid=l+r>>1;
	if(ql<=mid)insert(p<<1,l,mid,ql,qr,v);
	if(qr>mid)insert(p<<1|1,mid+1,r,ql,qr,v);
}
void solve(bitset<maxn>b,int p,int l,int r){
	for(ri i:a[p])b|=b<<i;
	if(l==r){ans|=b;return;}
	ri mid=l+r>>1;
	solve(b,p<<1,l,mid);
	solve(b,p<<1|1,mid+1,r);
}
int cnt,n,q;
int main(){
	n=qr(),q=qr();
	while(q--){
		ri x=qr(),y=qr(),z=qr();
		insert(1,1,n,x,y,z);
	}
	ans[0]=1;
	solve(ans,1,1,n);
	for(ri i=1;i<=n;++i)cnt+=ans[i];
	qw(cnt),putchar(10);
	for(ri i=1;i<=n;++i)
		if(ans[i])
			qw(i),putchar(32);
	return 0;
}