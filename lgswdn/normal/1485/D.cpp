#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=509;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,a[N][N],b[N][N];

signed main() {
	n=read(), m=read();
	rep(i,1,n) rep(j,1,m) a[i][j]=read();
	rep(i,1,n) rep(j,1,m) {
		if((i+j)%2) b[i][j]=720720;
		else {
			rep(q,1,33) {
				int p=q*q*q*q;
				int d=720720-p;
				if(p%a[i][j]==0) {
					b[i][j]=d;
					break;
				}
			}
		}
	}
	rep(i,1,n) {
		rep(j,1,m) printf("%lld ",b[i][j]);
		puts("");
	}
	return 0;
}