#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=59;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,r[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) r[i]=read();
		int ans=0;
		rep(i,1,n) if(r[i]!=2) ans++;
		printf("%d\n",ans);
	}
	return 0;
}