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

const int N = 1005;
int n,a[N],c[N],p[N];
ll b[N];
int main() {
	scanf("%d",&n);
	ll h1 = 0,h2 = 0; int id1 = 0,id2 = 0;
	fr(i,3,n) {
		printf("2 %d %d %d\n",1,2,i);
		fflush(stdout);
		scanf("%d",a+i);
		printf("1 %d %d %d\n",1,2,i);
		fflush(stdout);
		scanf("%lld",b+i);
		if(a[i] > 0) {
			if(h2 < b[i]) h2 = b[i],id2 = i;
		} else {
			if(h1 < b[i]) h1 = b[i],id1 = i;
		}
	}
	fr(i,3,n) if(a[i] < 0) {
		if(i == id1) continue;
		printf("2 %d %d %d\n",1,id1,i);
		fflush(stdout);
		scanf("%d",c+i);
	} else {
		if(i == id2) continue;
		printf("2 %d %d %d\n",1,id2,i);
		fflush(stdout);
		scanf("%d",c+i);
	}
	fr(i,1,n) p[i] = i;
	sort(p+2,p+n+1,[](const int &i,const int &j) {
		if(a[i] ^ a[j]) return a[i] < a[j];
		if(c[i] ^ c[j]) return c[i] < c[j];
		return c[i] == -1 ? b[i] < b[j] : b[i] > b[j];
	});
	printf("0 ");
	fr(i,1,n) printf("%d ",p[i]);
	puts(""); fflush(stdout);
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