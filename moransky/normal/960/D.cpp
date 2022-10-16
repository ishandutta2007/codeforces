// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 61;

int Q;

LL o[N];

int inline get(LL x) {
	int k = 0;
	while (x > 1) x >>= 1, k++;
	return k;
}

LL inline getId(LL x, int k) {
	return x - (1ll << k);
}

void inline add(LL &x, LL y, LL P) {
	x = (x % P + y % P + 2 * P) % P;
}

LL mod(LL x, LL P) {
	return (x % P + P) % P;
}

int main() {
	read(Q);
	while (Q--) {
		int op; LL X, K;
		read(op); read(X);
		if (op <= 2) read(K);
		LL c = get(X);
		K = mod(K, 1ll << c);
		if (op == 1) {
			add(o[c], K, 1ll << c);
		} else if (op == 2) {
			for (int i = c; i <= 60; i++) {
				add(o[i], K, 1ll << i);
				K = mod(K * 2, 1ll << (i + 1));
			}
		} else {
			LL p = getId(X, c);
			p = mod(p + o[c], 1ll << c);
			while (c >= 0) {
				printf("%lld ", (1ll << c) + mod(p - o[c], 1ll << c));
				c--;
				p = p / 2;
			}
			puts("");
		}
	}
    return 0;
}