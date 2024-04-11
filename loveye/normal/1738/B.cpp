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

const int N=1e5+5;
int n,k;
ll s[N],a[N];
int main() {
	int T=read();
	while(T--) {
		n=read(),k=read();
		fr(i,n-k+1,n) s[i]=read();
		if(k==1) {puts("Yes"); continue;}
		int ok=1;
		fo(i,n-k+2,n) if(s[i]-s[i-1]>s[i+1]-s[i]) {
			ok=0; break;
		}
		if(!ok) {puts("No"); continue;}
		int dt=s[n-k+2]-s[n-k+1];
		if(s[n-k+1]-1ll*(n-k+1)*dt>0) puts("No");
		else puts("Yes");
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}