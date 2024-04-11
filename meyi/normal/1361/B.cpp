#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10,mod=1e9+7;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
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
int k[maxn],n,p,t_case;
inline int qpow(int x,int y){
	int ret=1;
	for(;y;x=1ll*x*x%mod,y>>=1)if(y&1)ret=1ll*ret*x%mod;
	return ret;
}
int main(){
	t_case=qr();
	while(t_case--){
		n=qr(),p=qr();
		for(ri i=1;i<=n;++i)k[i]=qr();
		if(p==1){
			qw(n&1),putchar(10);
			continue;
		}
		sort(k+1,k+n+1,greater<int>());
		ri dif=0,sum1=0,sum2=0;
		for(ri i=1;i<=n;++i){
			if(i>1){
				if(dif)
					for(ri j=k[i-1];j>k[i];--j){
						dif*=p;
						if(dif>=n-i+1){
							for(ri l=i;l<=n;++l)sum2=(sum2+qpow(p,k[l]))%mod;
							goto output;
						}
					}
			}
			if(!dif)sum1=(sum1+qpow(p,k[i]))%mod,++dif;
			else sum2=(sum2+qpow(p,k[i]))%mod,--dif;
		}
		output:
		qw((sum1-sum2+mod)%mod),putchar(10);
	}
	return 0;
}