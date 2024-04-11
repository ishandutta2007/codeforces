#include<cstdio>
#include<cassert>
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
int n;
ll a[N];
int main() {
	scanf("%d",&n);
	fr(i,1,n) scanf("%lld",a+i);
	if(n==1) {
		printf("1 1\n%lld\n1 1\n0\n1 1\n0\n",-a[1]);
		return 0;
	}
	printf("%d %d\n",1,n-1);
	fr(i,1,n-1) {
		printf("%lld ",(a[i]%n+n)%n*(n-1));
		a[i]+=(a[i]%n+n)%n*(n-1);
	}
	puts("");
	printf("%d %d\n",2,n);
	fr(i,2,n) {
		printf("%lld ",(a[i]%n+n)%n*(n-1));
		a[i]+=(a[i]%n+n)%n*(n-1);
	}
	puts("");
	printf("%d %d\n",1,n);
	fr(i,1,n) {
		assert(a[i]%n==0);
		printf("%lld ",-a[i]);
	}
	puts("");
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}