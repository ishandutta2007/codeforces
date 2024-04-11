#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2009,inf=1e18;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,e[N][N],px=inf,d[N],vst[N];

signed main() {
	n=read();
	rep(i,1,n-1) rep(j,1,n-i) e[i+j][i]=e[i][i+j]=read(), px=min(px,e[i][i+j]);
	rep(i,1,n) rep(j,1,n) e[i][j]-=px;
	rep(i,1,n) {
		d[i]=e[i][i]=inf, vst[i]=0;
		rep(j,1,n) d[i]=min(d[i],2*e[i][j]);
	}
	d[0]=inf;
	rep(i,1,n) {
		int p=0;
		rep(j,1,n) if(!vst[j]&&d[j]<d[p]) p=j;
		vst[p]=1;
		rep(j,1,n) d[j]=min(d[j],d[p]+e[p][j]);
	}
	rep(i,1,n) printf("%lld\n",d[i]+(n-1)*px);
	return 0;
}