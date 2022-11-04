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

int T,n,m;

signed main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		int ans=1000000000;
		rep(i,1,30) {
			int l=1,r=1000000001,ret=-1;
			while(l<=r) {
				int mid=(l+r)/2,res=1;
				bool flag=1;
				rep(j,1,i) {
					res=res*mid;
					if(res>n) flag=0;
				}
				if(!flag) ret=mid, r=mid-1;
				else l=mid+1;
			}
			ans=min(ans,i+max(0ll,ret-m));
		}
		printf("%lld\n",ans);
	}
	return 0;
}