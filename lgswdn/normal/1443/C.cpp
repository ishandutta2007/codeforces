#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,a[N],b[N],sum;

bool check(int k) {
	int s=0;
	rep(i,1,n) if(a[i]>k) s+=b[i];
	return s<=k;
} 

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read(), sum=max(sum,a[i]);
		rep(i,1,n) b[i]=read();
		int l=0, r=sum, ans=r;
		while(l<=r) {
			int mid=(l+r)/2;
			if(check(mid)) r=mid-1, ans=mid;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}