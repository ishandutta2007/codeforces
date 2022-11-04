#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,x,y;

int calc(int n,int ret=0) {
	for(int l=1,r;l<=x&&l<=n;l=r+1) {
		r=min(x/(x/l),n);
		ret+=(r-l+1)*(x/l);
	}
	return ret;
}

signed main() {
	T=read();
	while(T--) {
		x=read(), y=read();
		int ans=0;
		int r=1;
		while(r<=y&&r*r+r-1<=x) r++; r--;
		rep(i,1,r) {
			ans=ans+(i*i+i-1)/(i+1);
		}
		ans=ans+calc(y+1)-calc(r+1);
		printf("%lld\n",ans);
	}
	return 0;
}