#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=100009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,k,a[N];

signed main() {
	T=read();
	while(T--) {
		n=read(); k=read();
		rep(i,1,n) a[i]=read();
		int t=0;
		rep(i,1,n) {
			if(a[i]*2<k) printf("%lld ",1ll);
			if(a[i]*2==k) printf("%lld ",t^=1);
			if(a[i]*2>k) printf("%lld ",0ll);
		}
		puts("");
	}
	return 0;
}