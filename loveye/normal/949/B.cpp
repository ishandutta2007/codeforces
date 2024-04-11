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

ll n,m;
int q;
ll f(ll k,ll x) {
	if(k==1) return 0;
	if(x&1) return f(k>>1,x+1>>1);
	return -(k>>1)-(x>>1)+1;
}
int main() {
	cin>>n; m=1ll<<__lg(n);
	ll rest=n-m;
	cin>>q;
	while(q--) {
		ll x; cin>>x;
		if(x<=2*rest) {
			if(x&1) cout<<(x+1>>1)<<endl;
			else cout<<n+f(m,rest-(x>>1)+1)<<endl;
		} else cout<<n+f(m,m-(x-2*rest)+1)<<endl;
	}
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}