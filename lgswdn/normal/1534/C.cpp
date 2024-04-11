#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=4e5+9,mod=1e9+7;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,m,a[N][2],p[N],ans=1;
bool vst[N];

signed main() {
	T=read();
	while(T--) {
		n=read(); ans=1;
		rep(i,1,n) a[i][0]=read(), vst[i]=0;
		rep(i,1,n) a[i][1]=read(), p[a[i][0]]=a[i][1];
		rep(i,1,n) if(!vst[i]) {
			int u=i;
			while(!vst[u]) vst[u]=1, u=p[u];
			ans=ans*2%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}