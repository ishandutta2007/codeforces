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
int a[maxn],cnt,d[maxn],id[maxn],len,n;
int main(){
	n=qr();
	for(ri i=1;i<=n;++i)d[i]=qr(),id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return d[x]>d[y];});
	for(ri i=1;i<=n;++i){
		a[i]=id[i]*2-1;
		if(i>1)qw(a[i-1]),putchar(32),qw(a[i]),putchar(10);
	}
	len=n;
	for(ri ii=1;ii<=n;++ii){
		ri i=id[ii];
		qw(a[ii+d[i]-1]),putchar(32),qw(i<<1),putchar(10);
		if(ii+d[i]-1==len)a[++len]=i<<1;
	}
	return 0;
}