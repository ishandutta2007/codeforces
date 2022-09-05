#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 1e6 + 5, MAXN = 1e6;

ll f[N], g[N];
deque <int> q[300005];
int n, m;

int main() {
    memset(f, -0x3f, sizeof(f));
    read(n); n = (n - 1) * 3;
    f[0] = 0;
    for (int pw = 1; pw <= 100000; pw *= 10) {
        for (int i = 0; i < pw * 3; i++) while (!q[i].empty()) q[i].pop_back();
        int w; read(w);
        for (int i = 0; i < MAXN; i++) {
            int id = i % (pw * 3);
            while (!q[id].empty() && f[i] - 1ll * (i / 3 / pw) * w >= f[q[id].back()] - 1ll * (q[id].back() / 3 / pw) * w) q[id].pop_back();
            if (!q[id].empty() && (i - q[id].front()) / 3 / pw > n) q[id].pop_front();
            q[id].push_back(i);
            g[i] = f[q[id].front()] + 1ll * (i - q[id].front()) / 3 / pw * w;
        }
        memset(f, -0x3f, sizeof(f));
        for (int i = 0; i <= 9; i++) {
            ll v = 0;
            if (i % 3 == 0) v = 1ll * w * i / 3;
            for (int j = MAXN - 1; j >= i * pw; j--) f[j] = max(f[j], g[j - i * pw] + v);
        }
    }
    read(m);
    while (m--) {
        int x; read(x);
        print(f[x], '\n');
    }
    return 0;
}