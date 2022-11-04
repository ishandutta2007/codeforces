#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=509,mod=998244353;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

char s[2];
int n,a[N],f[N][N],ans;

int pls(int x,int y) {x+=y; if(x>=mod) x-=mod; return x;}

signed main() {
	n=read();
	rep(i,1,n) {
		scanf("%s",s);
		if(s[0]=='-') a[i]=-1;
		else a[i]=read();
	}
	rep(i,1,n) if(a[i]>0) {
		int x=a[i];
		memset(f,0,sizeof(f)); f[0][0]=x;
		rep(j,1,n) {
			if(j!=i) {
				if(a[j]<0) {
					rep(k,0,n) f[j][k]=pls(f[j-1][k],f[j-1][k+1]);
					if(j<i) f[j][0]=pls(f[j][0],f[j-1][0]);
				} else {
					rep(k,0,n) {
						if(a[j]>a[i]||(a[j]==a[i]&&j>i)) f[j][k]=pls(f[j-1][k],f[j-1][k]);
						else {
							if(k!=0) f[j][k]=pls(f[j-1][k],f[j-1][k-1]);
							else f[j][k]=f[j-1][k];
						}
					}
				}
			} else {
				rep(k,0,n) f[j][k]=f[j-1][k];
			}
		}
		rep(k,0,n) ans=pls(ans,f[n][k]);
	}
	printf("%lld\n",ans);
	return 0;
}