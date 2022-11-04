#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,d[N],ans;

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) d[i]=read();
		if(n==1) {puts("0"); continue;}
		sort(d+1,d+n+1);
		ans=d[n];
		rep(i,1,n) ans-=(2*i-n-1)*d[i];
		printf("%lld\n",ans);
	}
	return 0;
}