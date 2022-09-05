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

const int N = 3e5 + 5;

struct seg_t {
    int mx[N << 2];

    void build(int u, int l, int r) {
        mx[u] = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int l, int r, int x, int y) {
        mx[u] = max(mx[u], y);
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (mid >= x) modify(u << 1, l, mid, x, y);
        else modify(u << 1 | 1, mid + 1, r, x, y);
    }

    int query(int u, int L, int R, int l, int r) {
        if (l <= L && R <= r) return mx[u];
        int mid = (L + R) >> 1, ans = 0;
        if (mid >= l) ans = max(ans, query(u << 1, L, mid, l, r));
        if (mid + 1 <= r) ans = max(ans, query(u << 1 | 1, mid + 1, R, l, r));
        return ans;
    }
} tr, rmq;

set <int> pos;
set <int> :: iterator it;
int a[N], cando[N], lpos[N], pre[N], ans[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        rmq.build(1, 1, n);
        for (int i = 1; i <= n; i++) read(a[i]), rmq.modify(1, 1, n, i, min(n, i + a[i]));
        tr.build(1, 1, n);
        for (int i = n; i >= 1; i--) {
            int r = min(i + a[i], n);
            if (i + 1 <= r) tr.modify(1, 1, n, i, tr.query(1, 1, n, i + 1, r));
            else tr.modify(1, 1, n, i, i);
        }
        for (int i = 1; i <= n + 1; i++) cando[i] = 0;
        cando[1] = 1;
        pos.clear();
        for (int i = 2; i <= n; i++) {
            if (cando[i - 1]) pos.insert(i - 1);
            it = pos.lower_bound(i - a[i]);
            if (it != pos.end()) {
                pre[i] = lpos[*it];
                int r = i - 1;
                if (lpos[*it] != *it) r = rmq.query(1, 1, n, *it, i - 1);
                else if (*it + 1 <= i - 1) r = rmq.query(1, 1, n, *it + 1, i - 1);
                if (r >= i + 1) r = tr.query(1, 1, n, i + 1, r);
                if (!cando[r + 1]) {
                    cando[r + 1] = 1;
                    lpos[r + 1] = i;
                }
                if (r == n) break;
            }
        }
        if (cando[n + 1]) {
            printf("YES\n");
            for (int i = 1; i <= n; i++) ans[i] = 0;
            int now = lpos[n + 1];
            while (now) {
                ans[now] = 1;
                now = pre[now];
            }
            for (int i = 1; i <= n; i++) {
                if (ans[i]) putchar('L');
                else putchar('R');
            }
            putchar('\n');
        } else {
            printf("NO\n");
        }
    }
    return 0;
}