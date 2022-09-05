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

int q, u, v;

int main() {
    read(q);
    while (q--) {
        int u, v;
        read(u); read(v);
        if (u > v) {
            printf("NO\n");
            continue;
        }
        int cando = 1;
        for (int i = 29; i >= 0; i--) {
            if ((v >> i) & 1) {
                if ((u >> i) & 1) {
                    v ^= (1 << i); u ^= (1 << i);
                    continue;
                }
                int ok = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if ((u >> j) & 1) {
                        ok = 1;
                        u ^= (1 << j);
                        break;
                    }
                }
                if (!ok) {
                    cando = 0;
                    break;
                }
                v ^= (1 << i);
                for (int j = i - 1; j >= 0 && u > v; j--) {
                    if ((u >> j) & 1) {
                        u ^= (1 << j);
                    }
                }
            }
        }
        if (cando) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}