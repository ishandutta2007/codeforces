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

const int N=5005;
int T,n,a[N];
ll s[N],dt[N];
int main() {
	T=read();
	while(T--) {
		n=read();
		fr(i,1,n) a[i]=read();
		fr(i,1,n) s[i]=0;
		ll ans=0;
		fr(d,1,n) {
			fo(b,1,d) if(a[b]>a[d]) ans+=s[b];
			fr(i,1,d) dt[i]=0;
			fo(c,1,d-1) if(a[c]<a[d]) ++dt[c+1],--dt[d];
			fr(i,1,d) dt[i]+=dt[i-1],s[i]+=dt[i];
		}
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