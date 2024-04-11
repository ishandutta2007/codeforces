#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<cctype>
#include<cstdio>
#define ri register int
const int maxn=1e5+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	do in=(in<<1)+(in<<3)+(ch^48),ch=getchar();while(isdigit(ch));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[maxn],m,n;
float x;
signed main(){
	n=qr();m=qr();
	for(ri i=1;i<=n;i++)a[i]=qr();
	while(m--){
		ri ans=0,op=qr(),l=qr(),r=qr();
		x=qr();
		if(op==1)
			for(ri i=l;i<=r;i++)a[i]-=(a[i]>x)?x:0;
		else{
			for(ri i=l;i<=r;i++)ans+=!(a[i]-x);
			qw(ans),putchar(10);
		}
	}
	return 0;
}