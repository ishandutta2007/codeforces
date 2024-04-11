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

struct seg {
    int l, r;
    seg (int a = 0, int b = 0) : l(a), r(b) {}
} g[N], tmp[N];

bool cmpl(seg a, seg b) { return a.l < b.l; }
bool cmpr(seg a, seg b) { return a.r > b.r; }

vector <int> adj[N];
set <pii> all, res;
int l[N], r[N], st[N], a[N], p[N], sl[N], sr[N], b[N], id1[N], id2[N], cnt[N], ban[N];
int T, n, q, top, root, ans, len, tmplen;

void dfs1(int u, int lim) {
    if (a[u] == 0) {
        sr[u] = lim;
    } else {
        if (lim < a[u]) {
            ans = 0;
        } else {
            lim = a[u];
        }
    }
    sl[u] = 0;
    for (auto v : adj[u]) {
        dfs1(v, lim);
        sl[u] = max(sl[u], sl[v]);
    }
    if (a[u] != 0) {
        if (sl[u] > a[u]) {
            ans = 0;
        } else {
            sl[u] = a[u];
        }
    }
}

void solve(vector <seg> a, vector <int> b) {
    if (a.size() == 1) {
        tmp[++tmplen] = a[0];
        // fprintf(stderr, "l = %d, r = %d\n", a[0].l, a[0].r);
        return;
    }
    for (int i = 0; i < (int)a.size(); i++) ban[i] = 0;
    sort(a.begin(), a.end(), cmpl);
    all.clear();
    int mid = (int)a.size() / 2, ok = 1;
    for (int i = 0, j = 0; i < mid; i++) {
        while (j < (int)a.size() && a[j].l <= b[i]) {
            all.insert(make_pair(a[j].r, j));
            ++j;
        }
        if (!all.size() || all.begin() -> first < b[i]) {
            ok = 0;
            break;
        }
        ban[all.begin() -> second] = 1;
        all.erase(all.begin());
    }
    if (ok) {
        vector <seg> va; vector <int> vb;
        for (int i = 0; i < (int)a.size(); i++) {
            if (!ban[i]) {
                va.push_back(a[i]);
            }
        }
        for (int i = mid; i < (int)b.size(); i++) vb.push_back(b[i]);
        solve(va, vb);
    }
    for (int i = 0; i < (int)a.size(); i++) ban[i] = 0;
    sort(a.begin(), a.end(), cmpr);
    all.clear();
    ok = 1;
    for (int i = (int)b.size() - 1, j = 0; i >= mid - 1; i--) {
        while (j < (int)a.size() && a[j].r >= b[i]) {
            all.insert(make_pair(a[j].l, j));
            ++j;
        }
        if (!all.size() || all.rbegin() -> first > b[i]) {
            ok = 0;
            break;
        }
        ban[all.rbegin() -> second] = 1;
        auto it = all.end(); --it;
        all.erase(it);
    }
    if (ok) {
        vector <seg> va; vector <int> vb;
        for (int i = 0; i < (int)a.size(); i++) {
            if (!ban[i]) {
                va.push_back(a[i]);
            }
        }
        for (int i = 0; i < mid - 1; i++) vb.push_back(b[i]);
        solve(va, vb);
    }
}

int main() {
    // freopen("1.in", "r", stdin);
    read(T);
    while (T--) {
        read(n); read(q); p[0] = p[n + 1] = 1e9;
        for (int i = 1; i <= n; i++) read(p[i]);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i <= n; i++) adj[i].clear();
        top = 0;
        for (int i = 1; i <= n; i++) {
            while (top && p[st[top]] < p[i]) --top;
            if (!top) l[i] = 0;
            else l[i] = st[top];
            st[++top] = i;
        }
        top = 0;
        for (int i = n; i >= 1; i--) {
            while (top && p[st[top]] < p[i]) --top;
            if (!top) r[i] = n + 1;
            else r[i] = st[top];
            st[++top] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (l[i] == 0 && r[i] == n + 1) {
                root = i;
            } else {
                if (p[l[i]] > p[r[i]]) {
                    adj[r[i]].push_back(i);
                } else {
                    adj[l[i]].push_back(i);
                }
            }
        }
        ans = 1;
        dfs1(root, 1e6);
        len = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                ++len;
                g[len] = seg(sl[i], sr[i]);
                // fprintf(stderr, "l = %d, r = %d\n", tl[len], tr[len]);
            }
        }
        for (int i = 1; i < len; i++) read(b[i]);
        sort(b + 1, b + len);
        if (!ans) {
            for (int i = 1; i <= q; i++) {
                int x; read(x);
                printf("NO\n");
            }
            continue;
        }
        vector <seg> nseg;
        vector <int> nb;
        for (int i = 1; i <= len; i++) nseg.push_back(g[i]);
        for (int i = 1; i < len; i++) nb.push_back(b[i]);
        tmplen = 0;
        solve(nseg, nb);
        res.clear();
        sort(tmp + 1, tmp + tmplen + 1, cmpl);
        int nowl = 0, nowr = -1;
        for (int i = 1; i <= tmplen; i++) {
            if (tmp[i].l <= nowr) {
                nowr = max(nowr, tmp[i].r);
            } else {
                if (nowr != -1) res.insert(make_pair(nowl, nowr));
                nowl = tmp[i].l; nowr = tmp[i].r;
            }
        }
        if (nowr != -1) res.insert(make_pair(nowl, nowr));
        for (int i = 1; i <= q; i++) {
            int x; read(x);
            auto it = res.lower_bound(make_pair(x + 1, 0));
            int ret = 0;
            if (it != res.begin()) {
                --it;
                if (it -> second >= x) ret = 1;
            }
            printf("%s\n", ret ? "YES" : "NO");
        }
    }
    return 0;
}