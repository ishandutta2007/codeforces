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
 
const int N = 1e5 + 5;

int n, m;

bool vis[N];

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        while (m--) {
            int a, b, c; read(a), read(b), read(c);
            vis[b] = 1;
        }
        int p = 1;
        while (vis[p]) p++;
        for (int i = 1; i <= n; i++)
            if (i != p) printf("%d %d\n", i, p);
        for (int i = 1; i <= n; i++) vis[i] = 0;
    }
    return 0;
}