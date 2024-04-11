#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=200009, inf=0x3f3f3f3f3f3f3f3f;

int n,a[N],f[N][3][2][2];

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}
void upd(int &x,int y) {x=(x>y ? x : y);}

signed main() {
	n=read();
	rep(i,1,n) a[i]=read();
	if(n==1) return printf("%lld\n",a[1]), 0; 
	rep(i,1,n) rep(r,0,2) rep(p,0,1) rep(q,0,1) f[i][r][p][q]=-inf;
	f[1][2][0][0]=-a[1], f[1][1][1][0]=a[1];
	rep(i,1,n-1) rep(r,0,2) rep(p,0,1) rep(q,0,1)
		upd(f[i+1][(r+2)%3][0][q||!p],f[i][r][p][q]-a[i+1]),
		upd(f[i+1][(r+1)%3][1][q|| p],f[i][r][p][q]+a[i+1]);
	printf("%lld\n",max(f[n][1][0][1],f[n][1][1][1]));
	return 0;
}