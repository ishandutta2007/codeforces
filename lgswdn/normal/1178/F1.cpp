#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=509,mod=998244353;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,c[N],f[N][N];
int dp(int l,int r) {
	if(f[l][r]) return f[l][r];
	if(l>=r) return f[l][r]=1;
	int ic=l;
	rep(i,l,r) if(c[i]<c[ic]) ic=i;
	int lf=0,rf=0;
	rep(x,l,ic) lf=(lf+dp(l,x-1)*dp(x,ic-1))%mod;
	rep(x,ic,r) rf=(rf+dp(ic+1,x)*dp(x+1,r))%mod;
	return f[l][r]=lf*rf%mod;
}

signed main() {
	n=read(), m=read();
	rep(i,1,m) c[i]=read();
	printf("%lld\n",dp(1,n));
	return 0;
}