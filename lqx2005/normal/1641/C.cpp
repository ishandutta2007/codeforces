#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
typedef long long ll;
typedef double db;
const int N = 2e5 + 10;
int n, q;
struct fenw {
    int t[N];
    void add(int x, int v) {
        for(; x <= n; x += x & (-x)) t[x] += v;
        return;
    }
    int sum(int x) {
        int res = 0;
        for(; x > 0; x -= x & (-x)) res += t[x];
        return res;
    }
}ds;
int st[N];
int sum[N << 1], sz[N << 1];
set<int> s, t;
vector<pair<int, int>> g[N << 1];
void build(int p, int l, int r) {
    sz[p] = r - l + 1;
    if(l == r) return;
    build(ls, l, mid), build(rs, mid + 1, r);
    return;
}
int query(int p, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return sum[p];
    }
    int res = 0;
    if(L <= mid) res += query(ls, l, mid, L, R);
    if(R > mid) res += query(rs, mid + 1, r, L, R);
    return res;
}
void modify(int p, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        g[p].emplace_back(L, R);
        return;
    }
    if(L <= mid) modify(ls, l, mid, L, R);
    if(R > mid) modify(rs, mid + 1, r, L, R);
    return;
}
void check(int p) {
    for(auto [l, r] : g[p]) {
        if(query(1, 1, n, l, r) > 0) continue;
        if(ds.sum(r) - ds.sum(l - 1) == 1) t.insert(*s.lower_bound(l));
    }
    return;
}
void change(int p, int l, int r, int x, int v) {
    if(v) g[p].clear();
    sum[p] += v;
    if(l == r) {
        sz[p] = 0, ds.add(l, -1), s.erase(l);
        check(p);
        return;
    }
    if(x <= mid) change(ls, l, mid, x, v);
    else change(rs, mid + 1, r, x, v);
    sz[p] = sz[ls] + sz[rs];
    if(sz[p] <= 1) check(p);
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(st, -1, sizeof(st));
    cin >> n >> q;
    for(int i = 1; i <= n; i++) s.insert(i), ds.add(i, 1);
    build(1, 1, n);
    for(int i = 1; i <= q; i++) {
        int opt, l, r, x;
        cin >> opt;
        if(opt == 0) {
            cin >> l >> r >> x;
            if(x == 1) {
                modify(1, 1, n, l, r);
                if(query(1, 1, n, l, r) == 0 && ds.sum(r) - ds.sum(l - 1) == 1) {
                    t.insert(*s.lower_bound(l));
                }
            } else {
                for(; ; ) {
                    auto it = s.lower_bound(l);
                    if(it != s.end() && *it <= r) {
                        int u = *it;
                        change(1, 1, n, u, 0), st[u] = 0;
                    } else break;
                }
            }
            for(; !t.empty(); ) {
                int u = *t.begin();
                t.erase(t.begin());
                st[u] = 1;
                change(1, 1, n, u, 1);
            }
        } else {
            cin >> x;
            if(st[x] == -1) cout << "N/A" << endl;
            else if(st[x] == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}