#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=109;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,m,b[N][N],l[N][N];
bool v[N][N];

signed main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) rep(j,1,m) b[i][j]=read();
		b[0][0]=1000000009;
		rep(u,1,m) {
			int x=0,y=0;
			rep(i,1,n) rep(j,1,m) if(b[i][j]<b[x][y]&&!v[i][j]) x=i,y=j;
			l[x][u]=b[x][y]; v[x][y]=1;
			rep(i,1,n) if(x!=i) {
				int p=0;
				rep(j,1,m) if(b[i][j]>b[i][p]&&!v[i][j]) p=j;
				l[i][u]=b[i][p]; v[i][p]=1;
			}
		}
		rep(i,1,n) {
			rep(j,1,m) printf("%lld ",l[i][j]);
			puts("");
		}
		rep(i,1,n) rep(j,1,m) v[i][j]=0;
	}
	return 0;
}