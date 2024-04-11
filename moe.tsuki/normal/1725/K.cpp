#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> id(N), A(N);
    iota(id.begin(), id.end(), 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int Q;
    cin >> Q;

    vector<int> pa(N + Q * 2), sz(N + Q * 2, 1);
    iota(pa.begin(), pa.end(), 0);

    map<int, int> mp;

    const auto dsu_anc = [&](int x) {
        const auto f = [&pa](auto self, int x) -> int {
            if (x == pa[x])
                return x;
            return pa[x] = self(self, pa[x]);
        };
        return f(f, x);
    };

    const auto dsu_join = [&](int x, int y) {
        x = dsu_anc(x);
        y = dsu_anc(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        pa[y] = x;
    };

    const auto Insert = [&](int val, int node) {
        if (mp.count(val)) {
            dsu_join(mp[val], node);
        } else {
            mp[val] = node;
        }
        A[dsu_anc(node)] = val;
    };

    const auto Join = [&](int l, int r, int val, int node) {
        auto lit = mp.lower_bound(l);
        auto rit = mp.lower_bound(r);
        if (lit == mp.end())
            return;
        for (auto it = lit; it != rit; it++) {
            dsu_join(it->second, node);
        }
        mp.erase(lit, rit);
        Insert(val, node);
    };


    A.resize(N + Q * 2);
    for (int i = 0; i < N; i++) {
        Insert(A[i], i);
    }

    int now = N;

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, w;
            cin >> k >> w;
            --k;
            id[k] = now++;
            Insert(w, id[k]);
        } else if (t == 2) {
            int k;
            cin >> k;
            --k;
            cout << A[dsu_anc(id[k])] << '\n';
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            int m = (l + r + 1) / 2;
            // [l, m), [m, r)
            Join(l, m, l-1, now++);
            Join(m, r+1, r+1, now++);
        }
        // for (auto [f, s]: mp)
        //     cerr << "mp["<<f<<"]="<<s<<", ";
        // cerr << endl;
    }
}