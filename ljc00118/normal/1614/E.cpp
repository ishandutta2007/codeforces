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

const int M = 3e7;

int lc[M], rc[M], tag[M], tot;
void add(int &u, int L, int R, int l, int r, int x) {
    if (!u) u = ++tot;
    if (l <= L && R <= r) {
        tag[u] += x;
        return;
    }
    int mid = (L + R) >> 1;
    if (mid >= l) add(lc[u], L, mid, l, r, x);
    if (mid + 1 <= r) add(rc[u], mid + 1, R, l, r, x);
}

int query(int u, int l, int r, int x) {
    if (!u) return 0;
    if (l == r) return tag[u];
    int mid = (l + r) >> 1, ans = tag[u];
    if (mid >= x) ans += query(lc[u], l, mid, x);
    else ans += query(rc[u], mid + 1, r, x);
    return ans;
}

const int N = 2e5 + 5, INF = 1e9;

vector <int> q[N];
int a[N];
int n, rt, ans;

int query(int x) {
    return query(rt, 0, INF, x);
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        int l = 0, r = 1e9, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid + query(mid) < a[i]) pos = mid, l = mid + 1;
            else r = mid - 1;
        }
        if (pos != -1) add(rt, 0, INF, 0, pos, 1);
        l = 0; r = 1e9; pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid + query(mid) > a[i]) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (pos != -1) add(rt, 0, INF, pos, INF, -1);
        int m; read(m);
        for (int j = 1; j <= m; j++) {
            int x; read(x);
            x = (x + ans) % (INF + 1);
            ans = query(x) + x;
            print(ans, '\n');
        }
    }
    return 0;
}