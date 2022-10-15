/* Never Say Die */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

#define MOD 1000000007

inline LL power(LL x, int y) {
	LL ret = 1;
	for (x %= MOD; y; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

#define inv(x) power(x, MOD - 2)

int n, nn;
LL ans = 0, C[400005], D[400005], E[400005];

int main() {
	read(n); nn = n / 2;
	LL now = 1;
	for (int i = 1; i <= nn; i++) {
		C[i] = now;
		now = (((now * LL(nn - i)) % MOD) * inv(i)) % MOD;
	}
			if (nn & 1) {
			for (int i = 1; i <= nn; i++) {
				D[i * 2 - 1] = C[i];
				D[i * 2] = C[i];
			}
		}
		else {
			for (int i = 1; i <= nn; i++) {
				D[i * 2 - 1] = C[i];
				D[i * 2] = MOD - C[i];
			}
		}

	if (n & 1) for (int i = 1; i <= n; i++) E[i] = ((i & 1 ? D[i] - D[i - 1] : D[i] + D[i - 1]) % MOD + MOD) % MOD;
	else for (int i = 1; i <= n; i++) E[i] = D[i];
	if (n == 1) E[1] = 1;
	for (int i = 1; i <= n; i++) {
		LL x; read(x);
		(ans += (E[i] * x) % MOD) %= MOD;
	}
	printf("%lld\n", (ans + MOD) % MOD);
	return 0;
}