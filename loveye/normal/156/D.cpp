#include<bits/stdc++.h>
using namespace std;

const int S = 1 << 21;
char p0[S],*p1,*p2;
#ifndef ZXY
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
#endif
inline int read() {
	static int x,c;x = 0;
	do{c = getchar();}while(!isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();}while(isdigit(c));
	return x;
}
#define LL long long
#define int long long

const int N = 1e5 + 5;
LL res = 1;
int n,m,p,ans,cnt;
int f[N],siz[N];
int getf(int x) {
	return f[x] == x ? x : f[x] = getf(f[x]);
}
inline void merge(int u,int v) {
	u = getf(u),v = getf(v);
	if(u != v) {
		f[u] = v;
		siz[v] += siz[u];
	}
}
LL qpow(LL a,int x) {
	LL res = 1;
	for(;x;x >>= 1) (x & 1) && (res = res * a % p),a = a * a % p;
	return res;
}
signed main() {
	scanf("%lld%lld%lld",&n,&m,&p);
	for(int i = 1;i <= n;++i)
		f[i] = i,siz[i] = 1;
	for(int i = 1,u,v;i <= m;++i)
		scanf("%lld%lld",&u,&v),merge(u,v);
	for(int i = 1;i <= n;++i)
		if(f[i] == i) (ans += siz[i]) %= p,++cnt,res = res * siz[i] % p;
	if(cnt == 1) ans = 1;
	else ans = qpow(ans,cnt-2) * res % p;
	printf("%lld\n",(ans + p) % p);
	return 0;
}