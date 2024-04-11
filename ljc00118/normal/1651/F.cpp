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

struct seg {
    int l, r, t, s;
    seg (int a = 0, int b = 0, int c = 0, int d = 0) : l(a), r(b), t(c), s(d) {}
};

struct atom {
    int x, a, b;
    atom (int c = 0, int d = 0, int e = 0) : x(c), a(d), b(e) {}
    bool operator < (const atom A) const { return x < A.x; }
};

vector <atom> p[N << 2];
vector <ll> suma[N << 2], sumb[N << 2];
seg st[N];
int a[N], b[N];
int n, q, top; ll ans;

void build(int u, int l, int r) {
    for (int i = l; i <= r; i++) p[u].push_back(atom((a[i] + b[i] - 1) / b[i], a[i], b[i]));
    sort(p[u].begin(), p[u].end());
    ll sa = 0, sb = 0;
    for (auto i : p[u]) {
        sa += i.a; sb += i.b;
        suma[u].push_back(sa);
        sumb[u].push_back(sb);
    }
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

ll query(int u, int L, int R, int l, int r, int t) {
    if (l <= L && R <= r) {
        int len = (int)p[u].size();
        int l = 0, r = len - 1, pos = len;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (p[u][mid].x > t) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (pos == 0) return 1ll * sumb[u][len - 1] * t;
        return 1ll * (sumb[u][len - 1] - sumb[u][pos - 1]) * t + suma[u][pos - 1];
    }
    int mid = (L + R) >> 1; ll ans = 0;
    if (mid >= l) ans += query(u << 1, L, mid, l, r, t);
    if (mid + 1 <= r) ans += query(u << 1 | 1, mid + 1, R, l, r, t);
    return ans;
}

ll calc(int l, int r, int t, int s) {
    if (s) {
        return min((ll)a[l], s + 1ll * b[l] * t);
    } else {
        return query(1, 1, n, l, r, t);
    }
}

ll x;
int find(int u, int L, int R, int l, int r, int t) {
    if (l <= L && R <= r) {
        int len = (int)p[u].size();
        int tl = 0, tr = len - 1, pos = len;
        while (tl <= tr) {
            int mid = (tl + tr) >> 1;
            if (p[u][mid].x > t) pos = mid, tr = mid - 1;
            else tl = mid + 1;
        }
        ll val;
        if (pos == 0) val = 1ll * sumb[u][len - 1] * t;
        else val = 1ll * (sumb[u][len - 1] - sumb[u][pos - 1]) * t + suma[u][pos - 1];
        if (val <= x) {
            x -= val;
            return 0;
        }
        if (L == R) return L;
        int mid = (L + R) >> 1, tmp = find(u << 1, L, mid, l, r, t);
        if (tmp) return tmp;
        return find(u << 1 | 1, mid + 1, R, l, r, t);
    }
    int mid = (L + R) >> 1;
    if (mid >= l) {
        int tmp = find(u << 1, L, mid, l, r, t);
        if (tmp) return tmp;
    }
    return find(u << 1 | 1, mid + 1, R, l, r, t);
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
    st[top = 1] = seg(1, n, -1e9, 0);
    build(1, 1, n);
    read(q);
    for (int i = 1; i <= q; i++) {
        int t;
        read(t); read(x);
        while (top) {
            ll tmp = calc(st[top].l, st[top].r, t - st[top].t, st[top].s);
            // fprintf(stderr, "l = %d, r = %d, t = %d, s = %d, tmp = %lld\n", st[top].l, st[top].r, st[top].t, st[top].s, tmp);
            if (tmp <= x) {
                x -= tmp;
                --top;
            } else {
                break;
            }
        }
        if (top) {
            seg tmp = st[top];
            int res;
            if (tmp.l != tmp.r) res = find(1, 1, n, tmp.l, tmp.r, t - tmp.t);
            else res = tmp.l;
            --top;
            if (res != tmp.r) st[top + 1] = seg(res + 1, tmp.r, tmp.t, 0), ++top;
            int now = min((ll)a[res], tmp.s + 1ll * b[res] * (t - tmp.t));
            st[top + 1] = seg(res, res, t, now - x);
            ++top;
        }
        if (top) {
            if (st[top].l != 1) st[top + 1] = seg(1, st[top].l - 1, t, 0), ++top;
        } else {
            st[++top] = seg(1, n, t, 0);
            ans += x;
        }
    }
    print(ans, '\n');
    return 0;
}