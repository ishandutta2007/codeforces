#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=1009;

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
		sort(a+1,a+n+1);
		int ans=0;
		rep(i,2,n) ans+=(k-a[i])/a[1];
		printf("%lld\n",ans);
	}
	return 0;
}