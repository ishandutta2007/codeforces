#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

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
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &


const int N = 300005;
int n;
LL sum1,a[N << 1],sum2,ans,inv[N << 1];
LL Cn[N],Cn1[N];
int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n*2;++i)
		scanf("%d",a+i);
	sort(a+1,a+n*2+1);
	for(int i = 1,x;i <= n;++i)
		(sum1 += a[i]) %= MOD;
	for(int i = 1,x;i <= n;++i)
		(sum2 += a[i+n]) %= MOD;
	inv[1] = 1;
	for(int i = 2;i <= n;++i)
		inv[i] = inv[MOD%i] * (MOD-MOD/i) % MOD;
	Cn[0] = 1;
	for(int i = 1;i <= n;++i)
		Cn[i] = Cn[i-1] * (n+1-i) % MOD * inv[i] % MOD;
	Cn1[0] = 1;
	for(int i = 1;i <= n-1;++i)
		Cn1[i] = Cn1[i-1] * (n-i) % MOD * inv[i] % MOD;
	for(int k = 0;k <= n;++k)
		(ans += Cn[k] * Cn1[n-k] % MOD * (sum2-sum1) % MOD) %= MOD;
	printf("%lld\n",(ans * 2 % MOD + MOD) % MOD);
	return 0;
}