// Skyqwq
#include <bits/stdc++.h>

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

const int N = 1 << 18;

int n, r, c[N];

LL s;

void inline out() {
    printf("%.9lf\n", (double)s / (1 << n));
}
 
int main() {
    read(n), read(r);
    for (int i = 0; i < (1 << n); i++) read(c[i]), s += c[i];
    out();
    while (r--) {
        int z, g; read(z), read(g);
        s += g - c[z];
        c[z] = g;
        out();
    }
    return 0;
}