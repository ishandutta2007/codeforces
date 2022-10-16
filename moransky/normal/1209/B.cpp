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

const int N = 105;

int n, ans;

int c[N], a[N], b[N];

int main() {
	read(n);
    for (int i = 1; i <= n; i++) scanf("%1d", c + i);
    for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
    for (int t = 0; t <= 10000; t++) {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            if (t < b[i]) {
                if (c[i] == 1) s++;
            } else {
                int st = c[i] ^ (((t - b[i]) / a[i] + 1) & 1);
                if (st == 1) s++;
            }
        }
        chkMax(ans, s);
    }
    printf("%d\n", ans);
}