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

int T,n,x,a[N],b[N];

signed main() {
	T=read();
	while(T--) {
		n=read(), x=read();
		rep(i,1,n) a[i]=read();
		rep(i,1,n) b[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+n+1); reverse(b+1,b+n+1);
		bool ans=1;
		rep(i,1,n) if(a[i]+b[i]>x) ans=0;
		if(ans==1) puts("YES");
		else puts("NO");
	}
	return 0;
}