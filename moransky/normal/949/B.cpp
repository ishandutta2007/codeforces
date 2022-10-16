// MoRanSky
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') x = x * 10 + (s ^ 48), s = getchar();
	x *= f;
}

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

LL n;
int q; 

typedef pair<LL, LL> PLL;

int t;

PLL e[100];

LL inline ask(LL x) {
	int p = t;
	while (x < e[p].fi) p--;
	while (1) {
		if (p == 1) return n;
		LL now = x - e[p].fi + 1; 
		if (now & 1) {
			now = (now + 1) / 2;
			p--;
			x = e[p].fi + now - 1;
		} else {
			return (x + 1) / 2;
		}
	}
}
 
 
int main() {
	read(n), read(q);
	e[++t] = mp(2 * n - 2, 2 * n - 2);
	LL len = 1;
	while (1) {
		len *= 2;
		++t;
		e[t] = mp(e[t - 1].fi - len, e[t - 1].fi - 1);
		if (e[t].fi <= 0) break;
	}
	while (q--) {
		LL x; read(x);
		printf("%lld\n", ask(x));
	}
}