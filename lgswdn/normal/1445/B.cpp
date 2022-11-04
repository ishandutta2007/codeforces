#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=59;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,a,b,c,d;

signed main() {
	T=read();
	while(T--) {
		a=read(), b=read(), c=read(), d=read();
		printf("%lld\n",max(a+b,c+d));
	}
	return 0;
}