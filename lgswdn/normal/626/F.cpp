#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=209, K=1009,mod=1e9+7;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,a[N],f[N][N][K],ans;

void pls(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

signed main() {
	n=read(), m=read();
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	f[0][0][0]=1;
	rep(i,0,n) rep(j,0,i) rep(k,0,m) {
		int s=j*(a[i+1]-a[i]);
		if(k+s>m) break;
		pls(f[i+1][j][k+s],1ll*f[i][j][k]*(j+1)%mod);
		pls(f[i+1][j+1][k+s],f[i][j][k]);
		if(j) pls(f[i+1][j-1][k+s],1ll*f[i][j][k]*j%mod);
		if(i==n&&j==0) pls(ans,f[i][j][k]);
	}
	printf("%d\n",ans);
	return 0;
}