#include<bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

inline long long read() {
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-48; c=getchar();}
	return x*f;
}

int T,W,H,xl,yl,xr,yr,w,h;

signed main() {
	T=read();
	while(T--) {
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&W,&H,&xl,&yl,&xr,&yr,&w,&h);
		int ans=0x3f3f3f3f3f3f3f3f;
		int x=w,y=h;
		if(x+xr-xl<=W) ans=min(ans,min(max(0ll,w-xl),max(0ll,xr-W+w)));
		if(y+yr-yl<=H) ans=min(ans,min(max(0ll,h-yl),max(0ll,yr-H+h)));
		if(ans==0x3f3f3f3f3f3f3f3f) {
			puts("-1");
		} else printf("%lld\n",ans);
	}
	return 0;
}