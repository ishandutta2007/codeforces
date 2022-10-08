
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;

struct segtree {
    int tree[8 * N], lazy[8 * N];
    segtree() {
        fill(tree, tree + 8 * N, 0);
        fill(lazy, lazy + 8 * N, 0);
    }
    int get(int i, int l, int r) {
        return tree[i] + lazy[i];
    }
    void prop(int i, int l, int r) {
        if(lazy[i] == 0) return;
        tree[i] += lazy[i];
        if(l < r) {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
    int query(int i, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return get(i, l, r);
        prop(i, l, r);
        int m = (l + r) / 2;
        return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
    }
    void upd(int i, int l, int r, int L, int R, int x) {
        if(r < L || R < l) return;
        if(L <= l && r <= R) {
            lazy[i] += x;
            return;
        }
        prop(i, l, r);
        int m = (l + r) / 2;
        upd(2 * i + 1, l, m, L, R, x);
        upd(2 * i + 2, m + 1, r, L, R, x);
        tree[i] = max(get(2 * i + 1, l, m), get(2 * i + 2, m + 1, r));
    }
    void ins(int i, int l, int r, int k, int x) {
        prop(i, l, r);
        if(l == r) {
            tree[i] = max(tree[i], x);
            return;
        }
        int m = (l + r) / 2;
        if(k <= m) ins(2 * i + 1, l, m, k, x);
        else ins(2 * i + 2, m + 1, r, k, x);
        tree[i] = max(get(2 * i + 1, l, m), get(2 * i + 2, m + 1, r));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    struct seg {
        int l, r, t;
        bool operator<(const seg &o) const {
            return r < o.r;
        }
    };
    vector<seg> S(n);
    vi ve;
    rep(i, 0, n) {
        cin >> S[i].l >> S[i].r >> S[i].t;
        ve.push_back(S[i].l);
        ve.push_back(S[i].r);
    }
    sort(all(ve));
    ve.erase(unique(all(ve)), ve.end());
    auto get = [&](int x) {
        return lower_bound(all(ve), x) - ve.begin();
    };
    for(auto &s : S) {
        s.l = get(s.l);
        s.r = get(s.r);
    }
    sort(all(S));
    segtree T1, T2;
    int ans = 0;
    int mx = sz(ve) + 5;
    for(auto &s : S) {
        int val = 1 + (s.t == 1 ? T1 : T2).query(0, 0, mx, 0, s.l);
        ans = max(ans, val);
        (s.t == 1 ? T2 : T1).ins(0, 0, mx, s.r + 1, val);
        (s.t == 1 ? T1 : T2).upd(0, 0, mx, 0, s.l, 1);
    }
    cout << ans << '\n';
}