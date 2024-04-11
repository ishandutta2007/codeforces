#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

ll l,r;
ll calc(ll x) {
	if(x==0) return 0;
	ll y=sqrt(x);
	while(y*y>x) --y;
	while((y+1)*(y+1)<=x) ++y;
	return (y-1)*3+(y*y<=x)+(y*(y+1)<=x)+(y*(y+2)<=x);
}
int main() {
	ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--) {
		cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<endl;
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}