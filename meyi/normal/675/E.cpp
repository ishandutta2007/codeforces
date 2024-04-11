#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
int a[maxn],n,st[maxn],tp;
ll ans,f[maxn];
int main(){
	n=qr();
	for(ri i=1;i<n;++i)a[i]=qr();
	ans=f[st[tp=1]=n-1]=1;
	for(ri i=n-2;i;--i){
		ri pos=*lower_bound(st+1,st+tp+1,a[i],greater<int>());
		ans+=(f[i]=f[pos]+pos-i+n-a[i]);
		while(tp&&a[i]>=a[st[tp]])--tp;
		st[++tp]=i;
	}
	printf("%lld",ans);
	return 0;
}