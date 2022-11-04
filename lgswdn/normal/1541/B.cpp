#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,a[N],b[N],ans;

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,2*n) b[i]=0;
		rep(i,1,n) a[i]=read(), b[a[i]]=i;
		ans=0;
		rep(s,3,2*n-1) {
			for(int x=1;x*x<s;x++) {
				if(s%x!=0) continue;
				int y=s/x;
				int i=b[x], j=b[y];
				if(i&&j&&i+j==s) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}