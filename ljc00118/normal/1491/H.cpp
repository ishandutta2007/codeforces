#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5, B = 350;

int a[N], tag[B], go[N];
int n, m;

void rebuild(int blk) {
    int l = (blk - 1) * B + 2, r = min(n, blk * B + 1);
    for (int i = l; i <= r; i++) {
        int to = max(a[i] - tag[blk], 1);
        if (to < l) go[i] = to;
        else go[i] = go[to];
    }
}

inline int getnxt(int pos) {
    int b = (pos - 2) / B + 1;
    if (tag[b] < B) return go[pos];
    return max(a[pos] - tag[b], 1);
}

int main() {
    read(n); read(m);
    for (int i = 2; i <= n; i++) read(a[i]);
    for (int i = 1; i <= (n - 2) / B + 1; i++) rebuild(i);
    while (m--) {
        int opt; read(opt);
        if (opt == 1) {
            int l, r, x;
            read(l); read(r); read(x);
            int bl = (l - 2) / B + 1, br = (r - 2) / B + 1;
            if (bl == br) {
                for (int j = l; j <= r; j++) a[j] = max(a[j] - x, 1);
                rebuild(bl);
            } else {
                for (int j = l; j <= bl * B + 1; j++) a[j] = max(a[j] - x, 1);
                for (int j = (br - 1) * B + 2; j <= r; j++) a[j] = max(a[j] - x, 1);
                rebuild(bl); rebuild(br);
                for (int j = bl + 1; j <= br - 1; j++) {
                    tag[j] = min(tag[j] + x, N);
                    if (tag[j] < B) rebuild(j);
                }
            }
        }
        if (opt == 2) {
            int u, v, preu, prev;
            read(u); read(v); preu = u; prev = v;
            while (u != v) {
                if (u < v) swap(u, v), swap(preu, prev);
                preu = u; u = getnxt(u);
            }
            while (preu != prev) {
                if (preu < prev) swap(preu, prev);
                int b = (preu - 2) / B + 1;
                preu = max(a[preu] - tag[b], 1);
            }
            print(preu, '\n');
        }
    }
    return 0;
}