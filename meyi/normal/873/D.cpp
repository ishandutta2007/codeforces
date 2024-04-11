#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char obuf[1000000],*o=obuf;
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
template<class T>
inline void ps(const T &s,char ed=10){
	for(const char &ch:s)if(ch)putchar(ch);
	putchar(ed);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[maxn],cnt,k,n;
void solve(int l,int r,bool t){
	if(l+1==r){
		a[l]=++cnt;
		return;
	}
	ri mid=l+r>>1;
	if(k>=2&&t){
		k-=2;
		solve(mid,r,1);
		solve(l,mid,1);
	}
	else{
		solve(l,mid,0);
		solve(mid,r,0);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	--k;
	solve(0,n,1);
	if(k)ps("-1");
	else for(ri i=0;i<n;++i)qw(a[i]),putchar(32);
	return 0;
}