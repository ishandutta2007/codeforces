#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;
const int MAXN = 2005, MAX = 200000;
const ll MOD = 1000000007LL;

struct Black{
	int x, y;
	bool operator < (const Black &rhs) const{
		return x + y < rhs.x + rhs.y;
	}
}b[MAXN];
ll dp[MAXN][2], f[MAX + 3], inv[MAX + 3];
int r, c, n;

ll quickPow(ll base, int times){
	ll ret = 1LL;
	while(times){
		if(times & 1) ret = ret * base % MOD;
		base = base * base % MOD;
		times >>= 1;
	}
	return ret;
}
ll C(int n, int m){
	if(n < 0 || m < 0 || n < m) return 0LL;
	return f[n] * inv[m] % MOD * inv[n - m] % MOD;
}
inline void update(ll &a, ll b){a += b; if(a >= MOD) a -= MOD;}
int main(){
	int i, j; ll w;
	f[0] = inv[0] = 1LL;
	for(i = 1; i <= MAX; ++ i) f[i] = f[i - 1] * i % MOD;
	inv[MAX] = quickPow(f[MAX], MOD - 2);
	for(i = MAX - 1; i; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
	scanf("%d%d%d", &r, &c, &n);
	for(i = 1; i <= n; ++ i) scanf("%d%d", &b[i].x, &b[i].y);
	n += 2; b[n - 1].x = b[n - 1].y = 1; b[n].x = r, b[n].y = c;
	sort(b + 1, b + 1 + n);
	dp[1][1] = 1LL;
	for(i = 2; i <= n; ++ i)
		for(j = 1; j < i; ++ j){
			w = C(b[i].x - b[j].x + b[i].y - b[j].y, b[i].x - b[j].x);
			update(dp[i][0], dp[j][1] * w % MOD);
			update(dp[i][1], dp[j][0] * w % MOD);
		}
	printf("%I64d\n", (dp[n][0] - dp[n][1] + MOD) % MOD);
	return 0;
}