/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;

#define MAXN 100319
#define MOD 1000000007

bool vis[MAXN];
int p[MAXN / 5], mu[MAXN], pcnt = 0;
int n, cnt[MAXN], a[MAXN], Max;
void init() {
	mu[1] = 1;
	for (int i = 2; i <= Max; i++) {
		if (!vis[i]) p[++pcnt] = i, mu[i] = -1;
		for (int j = 1; j <= pcnt && i * p[j] <= Max; j++) {
			vis[i * p[j]] = 1;
			if (i % p[j]) mu[i * p[j]] = -mu[i];
			else {mu[i * p[j]] = 0; break;}
		}
	}
	for (int i = 1; i <= Max; i++) {
		for (int j = i; j <= Max; j += i) {
			cnt[i] += a[j];
		}
	}
}

LL power(int x) {
	LL ret = 1, aa = 2;
	for ( ; x; x >>= 1) {
		if (x & 1) (ret *= aa) %= MOD;
		(aa *= aa) %= MOD;
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x]++;
		Max = max(Max, x);
	}
	init();
	LL ans = 0;
	for (int i = 1; i <= Max; i++) {
		if (cnt[i] && mu[i]) {
			(ans += (power(cnt[i]) - 1) * mu[i]) %= MOD;
		}
	}
	cout << (ans + MOD) % MOD << endl;
	return 0;
}