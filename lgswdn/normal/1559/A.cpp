#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=109;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,a[N];

signed main() {
	T=read();
	while(T--) {
		n=read(); int ans=(1ll<<30)-1;
		rep(i,1,n) a[i]=read(), ans&=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}