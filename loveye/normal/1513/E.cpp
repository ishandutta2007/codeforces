#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e5 + 5,MOD = 1e9 + 7;
int n,a[N];
LL ifac[N],fac[N];
inline LL qpow(LL a,int x) {
	LL res = 1;
	for(;x;x >>= 1) (x & 1) && (res = res * a % MOD),a = a * a % MOD;
	return res;
}
inline LL C(int n,int m) {
	return fac[n] * ifac[m] % MOD * ifac[n-m] % MOD;
}
map<int,int> mp;
int main() {
	LL sum = 0;
	scanf("%d",&n);
	fr(i,1,n) scanf("%d",a+i),sum += a[i];
	if(sum % n) cout << 0 << endl;
	else {
		sum /= n;
		fac[0] = 1;
		fr(i,1,n) fac[i] = fac[i-1] * i % MOD;
		ifac[n] = qpow(fac[n],MOD-2);
		rf(i,n-1,0) ifac[i] = ifac[i+1] * (i+1) % MOD;
		int cnt1 = 0,cnt2 = 0,cnt3 = 0;
		LL res = 1,ans = 0;
		fr(i,1,n) {
			if(a[i] == sum) ++cnt3;
			else if(a[i] < sum) ++cnt1;
			else ++cnt2;
			res = res * fac[mp[a[i]]] % MOD;
			++mp[a[i]];
			res = res * ifac[mp[a[i]]] % MOD;
		}
		if(cnt3 == n) ans = 1;
		else if(cnt1 == 1 || cnt2 == 1)
			ans = (cnt1 + cnt2) * fac[cnt2] * fac[cnt1] % MOD;
		else ans = fac[cnt1] * fac[cnt2] % MOD * 2 % MOD;
		ans = ans * C(n,cnt3) % MOD * fac[cnt3] % MOD * res % MOD;
		printf("%lld\n",ans);
	}
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