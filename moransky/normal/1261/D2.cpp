#include <iostream>
#include <cstdio>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 2e5 + 5, P = 998244353;

int n, tot, k, s = 1, ans, a[N], fact[N], infact[N];

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}


void inline factPrework(int n) {
	fact[0] = infact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
	infact[n] = power(fact[n], P - 2);
	for (int i = n - 1; i; i--) infact[i] = infact[i + 1] * (i + 1ll) % P;
}

int inline C(int a, int b) {
	if (a < b) return 0;
	return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

int inv2 = power(2, P - 2);

int inline get(int x) {
   if (x % 2 == 0) {
       return 1ll * (power(2, x) - C(x, x / 2) + P) * inv2 % P;
   } else {
       return power(2, x - 1);
   }
}

int main() {
    scanf("%d%d", &n, &k);
    factPrework(n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i % n + 1]) {
            s = 1ll * s * k % P;
        } else {
            ++tot;
        }
    }
    int v = 1;
    for (int i = 0; i <= tot; i++) {
        add(ans, 1ll * C(tot, i) * v % P * get(tot - i) % P);
        v = 1ll * v * (k - 2) % P;
    }
    printf("%lld\n", 1ll * ans * s % P);
    return 0;
}