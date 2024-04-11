/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef unsigned long long LL; 

#define P 2147483647
#define X 20000816
#define Q 233
#define Y 19260817
#define MOD 1000000007

struct Ha {
	LL a, b;
	bool operator == (Ha x) const {
		return a == x.a && b == x.b;
	}
	bool operator < (Ha x) const {
		return a < x.a ? 1 : ((a == x.a && b < x.b) ? 1 : 0);
	}
} a[1000005];

int n, m;
LL f[1000005], ans = 1;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, g; i <= n; i++) {
		scanf("%d", &g); 
		for (int j = 1, x; j <= g; j++) {
			scanf("%d", &x);
			a[x].a = ((a[x].a * P) ^ X) + i;
			a[x].b = ((a[x].b * Q) ^ Y) + i;
		}
	}
	sort(a + 1, a + m + 1);
	f[0] = 1;
	for (int i = 1; i <= m; i++) f[i] = (f[i - 1] * i) % MOD;
	for (int i = 1, j; i <= m; i = j) {
		j = i + 1;
		while (j <= m && a[j] == a[i]) j++;
		ans = (ans * f[j - i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}