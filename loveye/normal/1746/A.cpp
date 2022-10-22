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

const int N=55;
int n,k,a[N];
int main() {
	int T=read();
	while(T--) {
		n=read(),k=read();
		fr(i,1,n) a[i]=read();
		if(k==2) {
			int ok=0;
			fr(i,1,n) if(a[i]==1) ok=1;
			puts(ok?"Yes":"No");
			continue;
		}
		int need=n;
		while(need%(k-1)!=1) --need;
		need=n-need;
		int ok=0;
		fr(i,1,n) if(a[i]) if(max(i-1-1,0)+max(n-i-1,0)>=need) {
			ok=1; break;
		}
		puts(ok?"Yes":"No");
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}