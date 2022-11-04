#include<bits/stdc++.h>
#define int long long
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
		int n=read();
		if(n%2050!=0) {
			puts("-1");
			continue;
		}
		n/=2050;
		int ans=0;
		while(n) ans+=n%10, n/=10;
		printf("%lld\n",ans);
	}
	return 0;
}