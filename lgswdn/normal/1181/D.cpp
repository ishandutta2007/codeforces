#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int m,n,q,f[N],cnt[N];

signed main() {
	n=read(), m=read(), q=read();
	rep(i,1,n) {
		int a=read();
		f[i]=cnt[a]*m+a, cnt[a]++;
	}
	sort(f+1,f+n+1);
	rep(i,1,n) f[i]-=i;
	rep(i,1,q) {
		int k=read();
		printf("%lld\n",(k+(lower_bound(f+1,f+n+1,k-n)-f-n-2))%m+1);
	}
	return 0;
}