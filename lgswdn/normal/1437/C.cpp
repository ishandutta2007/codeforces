#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=209;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int Q,n,t[N],f[N][N<<1];

int main() {
	Q=read();
	while(Q--) {
		n=read();
		rep(i,1,n) t[i]=read();
		sort(t+1,t+n+1);
		memset(f,0x3f,sizeof(f));
		f[0][0]=0;
		rep(i,1,n) rep(j,i,2*n) rep(k,i-1,j-1) f[i][j]=min(f[i][j],f[i-1][k]+abs(t[i]-j));
		int ans=0x3f3f3f3f;
		rep(j,n,2*n) ans=min(ans,f[n][j]);
		printf("%d\n",ans);
	}
	return 0;
}