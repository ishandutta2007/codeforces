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

int T,p,q;

signed main() {
	T=read();
	while(T--) {
		p=read(), q=read();
		if(p<q) printf("%lld\n",p);
		else if(p%q!=0) printf("%lld\n",p);
		else {
			int ans=1;
			for(int i=2;i*i<=q;i++) {
				if(q%i==0) {
					int t=p;
					while(t%q==0) t/=i;
					ans=max(ans,t);
					while(q%i==0) q/=i;
				}
			}
			if(q!=1) {
				while(p%q==0) p/=q;
				ans=max(ans,p);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
//