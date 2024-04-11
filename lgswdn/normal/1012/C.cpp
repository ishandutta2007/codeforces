#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N],f[N][N][3];

int main() {
	n=read();
	rep(i,1,n) a[i]=read();
	memset(f,0x3f,sizeof(f));
	f[1][0][0]=f[1][1][1]=0;
	rep(i,2,n) {
		rep(j,0,(i+1)/2) {
			f[i][j][0]=min(f[i-1][j][0],f[i-1][j][2]);
			f[i][j][1]=min(f[i-1][j-1][0]+max(0,a[i-1]-a[i]+1),f[i-1][j-1][2]+max(0,min(a[i-1],a[i-2]-1)-a[i]+1));
			f[i][j][2]=f[i-1][j][1]+max(0,a[i]-a[i-1]+1);
		}
	}
	rep(k,1,(n+1)/2) printf("%d ",min(f[n][k][0],min(f[n][k][1],f[n][k][2]))); puts("");
	return 0;
}