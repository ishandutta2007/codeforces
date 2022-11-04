#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1009,mod=1e9+7;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,f[N][N],ans;

signed main() {
	n=read();
	f[0][0]=1;
	rep(i,1,n) rep(j,0,i) f[i][j]=(f[i-1][j]+(j?f[i][j-1]:0))%mod;
	rep(i,1,n) rep(j,0,i) ans=(ans+(i+j)%2*f[i][j])%mod;
	printf("%lld\n",ans);
	return 0;
}