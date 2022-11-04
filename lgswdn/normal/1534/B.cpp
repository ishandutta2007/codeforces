#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=4e5+9;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,m,a[N],ans;

signed main() {
	T=read();
	while(T--) {
		n=read(), ans=0; a[n+1]=0;
		rep(i,1,n) a[i]=read();
		rep(i,1,n+1) ans+=abs(a[i]-a[i-1]);
		rep(i,1,n) if(a[i]>a[i-1]&&a[i]>a[i+1]) ans-=a[i]-max(a[i-1],a[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}