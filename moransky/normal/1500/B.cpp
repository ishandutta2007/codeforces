// Skyqwq
#include <iostream>
#include <cstdio>
 
using namespace std;
 
typedef long long LL;
 
char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
 
void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}
 
void print(int x) { //
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
const int N = 1e6 + 5;
 
int n, m, pos[N], a[N], b[N];
 
LL k;
 
LL inline exgcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	LL d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
 
LL X, Y; 
LL d;
 
LL inline ask(int i, int j, LL mid) {
	LL x = X, y = Y;
	if ((j - i) % d) return 0;
	LL t = (j - i) / d;
	x *= t, y *= t;
	LL mod = m / d;
	x = (x % mod + mod) % mod;
	if (x * n + i > mid) return 0;
	LL k = ((mid - i) / n - x) / (m / d);
	return k + 1;
}
 
bool inline check(LL mid) {
	LL s = mid;
	for (int i = 1; i <= n; i++) {
		if (pos[a[i]]) s -= ask(i, pos[a[i]], mid);
	}
	return k <= s;
}
 
int main() {
	scanf("%d%d%lld", &n, &m, &k); d = exgcd(n, m, X, Y);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int j = 1; j <= m; j++) scanf("%d", b + j), pos[b[j]] = j;
	LL l = 0, r = 2e18;
	while (l < r) {
		LL mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", r);
	return 0;
}