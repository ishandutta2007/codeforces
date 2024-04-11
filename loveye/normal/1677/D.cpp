#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e6+5,MOD=998244353;
int n,a[N],k;
int main() {
	int T=read();
	while(T--) {
		n=read(); k=read();
		fr(i,1,n) a[i]=read();
		rotate(a+1,a+n-k+1,a+n+1);
		ll ans=1;
		fr(i,1,n) if(a[i]==-1) ans=ans*i%MOD;
		else if(a[i]>0) ans=ans*(a[i]+k<i);
		else ans=ans*min(k+1,i)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}

inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}