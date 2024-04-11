// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5, S = 7001;

int n, q, mu[S];

bitset<S> f[N], g[S], h[S];

bool st[S];

int pr[S], t;
 
void inline prework(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i)
            g[j][i] = 1;
    }
    for (int i = 1; i <= n; i++) mu[i] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) pr[++t] = i, mu[i] = -1;
        for (int j = 1; pr[j] * i <= n; j++) {
            int v = pr[j] * i;
            st[v] = 1;
            if (i % pr[j] == 0) {
                mu[v] = 0;
                break;
            }
            mu[v] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            if (mu[j]) h[i][i * j] = 1;
        }
    }
}

int main() {
    prework(7000);
    read(n), read(q);
    while (q--) {
        int op, x, y; read(op), read(x), read(y);
        if (op == 1) {
            f[x] = g[y];
        } else if (op == 2) {
            int z; read(z);
            f[x] = f[y] ^ f[z];
        } else if (op == 3) {
            int z; read(z);
            f[x] = f[y] & f[z];
        } else {
            int ans = (f[x] & h[y]).count();
            printf("%d", ans & 1);
        }
    }   
    return 0;
}