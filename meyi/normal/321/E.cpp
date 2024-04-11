#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxk=810,maxn=4010;
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
int a[maxn][maxn],f[maxk][maxn],k,n;
void solve(int l,int r,int L,int R,int k){
	if(l>r||L>R)return;
	ri mid=l+r>>1,pos=0,val=INT_MAX;
	for(ri i=L;i<mid&&i<=R;++i){
		ri tmp=f[k-1][i]+a[i+1][mid];
		if(tmp<val)pos=i,val=tmp;
	}
	f[k][mid]=val;
	solve(l,mid-1,L,pos,k);
	solve(mid+1,r,pos,R,k);
}
int main(){
	n=qr(),k=qr();
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=n;++j)
			if(i<j)a[i][j]=a[i][j-1]+qr();
			else qr();
	for(ri i=n;i;--i)
		for(ri j=1;j<=n;++j)
			if(i<j)a[i][j]+=a[i+1][j];
	clear(f[0],n,0x3f);
	f[0][0]=0;
	for(ri i=1;i<=k;++i)solve(1,n,0,n,i);
	qw(f[k][n]);
	return 0;
}