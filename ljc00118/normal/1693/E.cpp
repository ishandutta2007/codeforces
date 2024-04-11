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

const int N = 2e5 + 5;

int a[N], id[N], f[N];
int n, pl, pr; ll ans;

bool cmp(int i, int j) { return a[i] != a[j] ? a[i] < a[j] : i < j; }

void add(int x, int y) {
    while (x <= n) {
        f[x] += y;
        x += (x & -x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += f[x];
        x &= (x - 1);
    }
    return ans;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        if (a[i] == 0) {
            --i; --n;
            continue;
        }
        id[i] = i;
    }
    if (n == 0) {
        print(0, '\n');
        return 0;
    }
    sort(id + 1, id + n + 1, cmp);
    pl = 1; pr = n;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;
        while (r < n && a[id[l]] == a[id[r + 1]]) ++r;
        for (int i = l; i <= r; i++) ans += query(id[i]) + 1;
        int nl = id[l], nr = id[r];
        if (nr <= pl) {
            add(nl, 1); add(pl, -1);
            pr = pl - 1; pl = nl;
        } else if (nl >= pr) {
            add(pr + 1, 1); add(nr + 1, -1);
            pl = pr + 1; pr = nr;
        } else {
            add(nl, 1); add(nr + 1, -1);
            pl = nl; pr = nr;
        }
    }
    print(ans, '\n');
    return 0;
}