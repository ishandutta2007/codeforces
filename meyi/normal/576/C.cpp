#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
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
int bel[maxn],cnt;
struct qry{
	int l,r,id;
	inline bool operator<(const qry &k)const{
		return bel[l]!=bel[k.l]?l<k.l:(bel[l]&1)?r<k.r:r>k.r;
	}
}q[maxn];
int m,n;
signed main(){
	n=qr();
	m=max(2,(int)sqrt(n));
	for(ri i=1;i<=n;++i){
		q[i].l=qr(),q[i].r=qr(),q[i].id=i;
		if(i%m==1)++cnt;
		bel[i]=cnt;
	}
	sort(q+1,q+n+1);
	for(ri i=1;i<=n;++i)qw(q[i].id),putchar(32);
	return 0;
}