#include <iostream>
#include <cstdio>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


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

const int N = 2e5 + 5;

int n, d[N], c[N];

bool inline check(int x) {
    int p = n + 1;
    for (int i = 1; i <= n; i++)
        if (d[i] > x) { p = i; break; }
    for (int i = 1; i <= n; i++) {
        if (d[i] <= x) c[i] = 1;
        else c[i] = 2;
    }
    for (int i = 1; i < p; i++) {
        if (d[i] == x) c[i] = 2;
    }
    int la = 0;
    bool o = 1;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) {
            if (d[i] < la) {
                o = 0;
                break;
            }
            la = d[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == 2) {
            if (d[i] < la) {
                o = 0;
                break;
            }
            la = d[i];
        }
    }
    if (!o) return 0;
    for (int i = 1; i <= n; i++) printf("%d", c[i]);
    puts("");
    return 1;
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
        for (int i = 1; i <= n; i++) scanf("%1d", d + i);
        bool ok = 0;
        for (int i = 0; i < 10; i++) {
            if (check(i)) {
                ok = 1;
                break;
            }
        }
        if (!ok) puts("-");
	}
}