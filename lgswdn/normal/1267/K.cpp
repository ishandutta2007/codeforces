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

int T,k,f[209],s[209];

signed main() {
	T=read();
	while(T--) {
		k=read();
		int cnt=0;
		while(k) {
			f[cnt]=k%(cnt+2);
			k/=(cnt+2), cnt++;
		}
		sort(f,f+cnt); reverse(f,f+cnt);
		int lst=0;
		rep(i,0,cnt-1) {
			if(i==0||f[i]!=f[i-1]) lst=i;
			s[i]=i-lst+1;
		}
		int ans1=1, ans2=1;
		rep(i,0,cnt-1) ans1=ans1*max(0ll,cnt-i-max(0ll,f[i]-1))/s[i];
		if(f[cnt-1]!=0) ans2=0;
		else {
			rep(i,0,cnt-2) ans2=ans2*max(0ll,cnt-1-i-max(0ll,f[i]-1))/s[i];
		}
		printf("%lld\n",ans1-ans2-1);
	}
	return 0;
}