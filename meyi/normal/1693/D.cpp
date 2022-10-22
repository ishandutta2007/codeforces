#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
int a[maxn],ans[maxn],f[maxn][2],n;
inline void dp(int k){
	f[k][0]=n+1,f[k][1]=0;
	for(ri i=k+1;i<=n;++i){
		f[i][0]=0,f[i][1]=n+1;
		if(a[i-1]<a[i])f[i][0]=f[i-1][0];
		if(a[i-1]>a[i])f[i][1]=f[i-1][1];
		if(f[i-1][1]<a[i])ckmax(f[i][0],a[i-1]);
		if(f[i-1][0]>a[i])ckmin(f[i][1],a[i-1]);
		if(f[i][0]==0&&f[i][1]==n+1){ans[k]=i-1;return;}
	}
	ans[k]=n;
}
void solve(int l,int r){
	if(l+1>=r)return;
	if(ans[l]==ans[r]){for(ri i=l;i<=r;++i)ans[i]=ans[l];return;}
	ri mid=l+r>>1;
	dp(mid);
	solve(l,mid),solve(mid,r);
}
int main(){
	n=qr();
	for(ri i=1;i<=n;++i)a[i]=qr();
	dp(1),dp(n);
	solve(1,n);
	printf("%lld",accumulate(ans+1,ans+n+1,0ll)-1ll*n*(n-1)/2);
	return 0;
}