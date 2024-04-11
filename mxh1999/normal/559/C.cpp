#include <cstdio>
#include <cstring>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)

typedef long long LL;
const int MOD = 1000000007;
const LL MODLL = 1000000007LL;

inline LL pow(LL x, int y){
	LL ans = 1;
	h(i, 30, 0){
		ans = ans * ans % MODLL;
		if(y & (1 << i)) ans = ans * x % MODLL;
	}
	return ans;
}
inline LL inv(LL x){
	return pow(x, MOD - 2);
}

LL fac[10000086], invfac[100086], _dp[2010];
int d, n, a[108], x[2010][108];

inline LL paths(int a, int b){
	LL ans = 1; int sum = 0;
	f(j, 1, d) if(x[a][j] > x[b][j]) return -1LL;
	else{
		int dx = x[b][j] - x[a][j];
		sum += dx; ans = ans * invfac[dx] % MODLL;
	}
	return ans * fac[sum] % MODLL;
}
inline LL dp(int x){
	LL &ans = _dp[x];
	if(ans != -1LL) return ans;
	ans = paths(0, x);
	f(i, 1, n + 1) if(x != i){
		LL cp = paths(i, x);
		if(cp != -1LL) ans = (ans + MODLL - dp(i) * cp % MODLL) % MODLL;
	}
	// printf("dp %d = %I64d\n", x, ans);
	return ans;
}

int main(){
	fac[0] = 1;
	f(i, 1, 10000008) fac[i] = fac[i - 1] * (LL) i % MODLL;
	invfac[0] = 1;
	f(i, 1, 100008) invfac[i] = invfac[i - 1] * inv(i) % MODLL;
	d=2;
	f(j, 1, d) {scanf("%d", a + j);a[j]--;}
	scanf("%d", &n);
	f(i, 1, n) f(j, 1, d) {scanf("%d", &x[i][j]);x[i][j]--;}
	f(j, 1, d){
		x[0][j] = 0; x[n + 1][j] = a[j];
	}
	memset(_dp, 0xff, sizeof(_dp)); _dp[0] = 1;
	printf("%I64d\n", dp(n + 1));
	return 0;
}