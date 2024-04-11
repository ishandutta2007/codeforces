#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int n,p[N];
int main() {
	for(int T=read();T--;) {
		n=read();
		p[1]=n/2+1; p[n]=n/2;
		ll ans1=0;
		fr(i,n/2+1,n-1) ans1+=1ll*(i-1)*(i-1),p[i]=i+1;
		fr(i,2,n/2) ans1+=1ll*(n-i)*(n-i),p[i]=i-1;
		printf("%lld\n",ans1+1ll*(n-1)*(n-1));
		fr(i,1,n) printf("%d ",p[i]);
		puts("");
		printf("%d\n",n-1);
		fr(i,n/2+1,n-1) printf("%d %d\n",i,1);
		rf(i,n/2,2) printf("%d %d\n",i,n);
		printf("%d %d\n",1,n);
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}