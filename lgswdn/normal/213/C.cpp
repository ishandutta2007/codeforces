#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=309;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N][N],f[N<<1][N][N];

void upd(int &x,int y) {x=max(x,y);}

int main() {
	n=read();
	rep(i,1,n) rep(j,1,n) a[i][j]=read();
	memset(f,-0x3f,sizeof(f));
	f[1][1][1]=0;
	rep(k,1,2*n-1) {
		rep(i,max(1,1+k-n),min(k,n)) {
			rep(j,max(1,1+k-n),min(k,n)) {
				int val=(i==j?a[i][k-i+1]:a[i][k-i+1]+a[j][k-j+1])+f[k][i][j];
				upd(f[k+1][i][j],val),
				upd(f[k+1][i+1][j],val),
				upd(f[k+1][i][j+1],val),
				upd(f[k+1][i+1][j+1],val);
			}
		}
	}
	printf("%d\n",f[2*n-1][n][n]+a[n][n]);
	return 0;
}