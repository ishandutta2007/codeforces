#include<bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int N=1e5+9;

inline long long read() {
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-48; c=getchar();}
	return x*f;
}

int T,m,s[2][N],a[2][N];

signed main() {
	T=read();
	while(T--) {
		m=read();
		rep(i,1,m) a[0][i]=read();
		rep(i,1,m) a[1][i]=read();
		rep(i,1,m) s[0][i]=s[0][i-1]+a[0][i];
		rep(i,1,m) s[1][i]=s[1][i-1]+a[1][i];
		int ans=0x3f3f3f3f;
		rep(i,1,m) {
			ans=min(ans,max(s[0][m]-s[0][i],s[1][i-1]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}