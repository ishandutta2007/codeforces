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
#define y1 y111

ll x1,y1,x2,y2,a,b,n = 1000000000;
int main() {
	printf("? %lld %lld\n",1ll,1ll);
	fflush(stdout);
	scanf("%lld",&a);
	printf("? %lld %lld\n",n,1ll);
	fflush(stdout);
	scanf("%lld",&b);
	if(~(a ^ b) & 1) ++b;
	//x + y == a + 2
	//x - y == n - b - 1
	x1 = (a + 2) + (n - b - 1) >> 1;
	printf("? %lld %lld\n",x1,1ll);
	fflush(stdout);
	scanf("%lld",&y1); ++y1;
	x1 = a + 2 - y1;

	printf("? %lld %lld\n",1ll,n);
	fflush(stdout);
	scanf("%lld",&a);
	printf("? %lld %lld\n",n,n);
	fflush(stdout);
	scanf("%lld",&b);
	if(~(a ^ b) & 1) ++a;
	//x - y == 1 + a - n
	//x + y == n - b + n
	x2 = (1 + a - n) + (n - b + n) >> 1;
	printf("? %lld %lld\n",x2,n);
	fflush(stdout);
	scanf("%lld",&y2); y2 = n - y2;
	x2 = n - b + n - y2;
	printf("! %lld %lld %lld %lld\n",x1,y1,x2,y2);
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