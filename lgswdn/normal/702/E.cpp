#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,K,f[N][39],g[N][39],h[N][39];

signed main() {
	n=read(), K=read();
	rep(i,1,n) f[i][0]=read()+1;
	rep(i,1,n) g[i][0]=h[i][0]=read();
	rep(k,1,35) rep(i,1,n) {
		f[i][k]=f[f[i][k-1]][k-1],
		g[i][k]=g[i][k-1]+g[f[i][k-1]][k-1],
		h[i][k]=min(h[i][k-1],h[f[i][k-1]][k-1]);
	}
	rep(i,1,n) {
		int ans1=0,ans2=0x3f3f3f3f3f3f3f3f,u=i;
		per(k,35,0) if((1ll<<k)&K)
			ans1+=g[u][k],ans2=min(ans2,h[u][k]),u=f[u][k];
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}