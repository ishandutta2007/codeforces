#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9,mod=1e9+7;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,m,c[N],k[N];

signed main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) k[i]=read();
		rep(i,1,m) c[i]=read();
		sort(k+1,k+n+1); reverse(k+1,k+n+1);
		int pos=1,ans=0;
		rep(i,1,n) {
			if(pos<=m&&pos<=k[i]) {
				ans+=c[pos++];
			} else {
				ans+=c[k[i]];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}