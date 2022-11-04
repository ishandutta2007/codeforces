#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,q,k,a[N],f[N],s[N];

signed main() {
	n=read(), q=read(), k=read();
	rep(i,1,n) a[i]=read();
	a[0]=0, a[n+1]=k+1;
	rep(i,1,n) f[i]=a[i+1]-a[i-1]-2, s[i]=s[i-1]+f[i];
	rep(i,1,q) {
		int l=read(), r=read(), ans=0;
		ans=s[r-1]-s[l];
		ans+=(a[l+1]-a[0]-2);
		ans+=(a[n+1]-a[r-1]-2);
		printf("%lld\n",ans);
	}
	return 0;
}