#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,m;

signed main() {
	T=read();
	while(T--) {
		n=read();
		if(n%2==0) {
			rep(i,1,n/2) printf("%d %d ",i*2,i*2-1); puts("");
		} else {
			printf("%d %d %d ",3,1,2);
			rep(i,4,n) printf("%d ",i^1);
			puts("");
		}
	}
	return 0;
}