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

const int N=105;
int n,a[N];
int main() {
	int T=read();
	while(T--) {
		n=read();
		int fl=0,c=0;
		fr(i,1,n) {
			a[i]=read();
			if(a[i]&1) ++c;
			else fl^=1;
		}
		if(fl) {
			if(c%4==2) cout<<"Bob\n";
			else cout<<"Alice\n";
		} else {
			if(c%4==0||c%4==3) cout<<"Alice\n";
			else cout<<"Bob\n";
		}
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}