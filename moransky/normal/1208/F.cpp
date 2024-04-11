// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
const int N = 2100005;

typedef pair<int, int> PII;

int n, a[N];

PII f[N];

void inline chk(PII &x, int y) {
	if (y == x.fi || y == x.se) return;
	if (y > x.fi) x.se = x.fi, x.fi = y;
	else if (y > x.se) x.se = y;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		chk(f[a[i]], i);
	}
	for (int i = (1 << 21) - 1; ~i; i--) {
		for (int j = 0; j < 21; j++) {
			if (i >> j & 1) {
				int t = i ^ (1 << j);
				chk(f[t], f[i].fi);
				chk(f[t], f[i].se);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		int res = 0, pt = 0;
		for (int j = 20; ~j; j--) {
			if (a[i] >> j & 1) {
				res |= 1 << j;
			} else {
				if (f[pt + (1 << j)].se > i) {
					res |= 1 << j;
					pt |= 1 << j;
				}
			}
		}
		chkMax(ans, res);
	}
	print(ans);
	return 0;
}