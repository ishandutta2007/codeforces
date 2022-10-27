#include<bits/stdc++.h>
using namespace std;
int constexpr nax = 3e5 + 5;
using ll = int64_t;
const int INF = 1e9;

template<typename T>
struct fenwick {
    T bit[nax];
    fenwick() {
        memset(bit, 0, sizeof(bit));
    }
    void update(int x, T val) {
        for (; x < nax ; x += x & -x)
            bit[x] += val;
    }
    T get(int x) {
        int res = 0;
        for (; x > 0 ; x -= x & -x)
            res += bit[x];
        return res;
    }
    T get(int l, int r) {
        return get(r) - get(l - 1);
    }
};
struct segtree {
    static constexpr int Mx = 4 * nax;
    ll sg[Mx] = {}, tag[Mx] = {};
    inline void pull (int v) {
        sg[v] = min(sg[v * 2], sg[v * 2 + 1]);
    }
    segtree() {
        fill(sg, sg + Mx, INF);
        fill(tag, tag + Mx, 0);
    }
    inline void push(int v) {
        if (v * 2 + 1 < Mx && tag[v]) {
            sg[v * 2] +=  tag[v];
            sg[v * 2 + 1] += tag[v];
            tag[v * 2] +=  tag[v];
            tag[v * 2 + 1] += tag[v];
        }
        tag[v] = 0;
    }
    inline void update(int v, int x, int y, int l, int r , ll val) {
        push(v);
        if (l > r) return ;
        if (l == x && r == y) {
            sg[v] += val; tag[v] += val;
            return push(v);
        }
        int mid = x + y >> 1;
        update(v * 2, x , mid, l, min(r, mid), val);
        update(v * 2 + 1, mid + 1, y, max(l, mid + 1), r, val);
        pull(v);
    }
    int find_first_neg(int v, int x, int y) {
        push(v);
        if (x == y) {
            assert(sg[v] <= 0);
            return x;
        } else {
            int mid = x + y >> 1;
            if (sg[v * 2] <= 0) return find_first_neg(v * 2, x, mid);
            else return find_first_neg(v * 2 + 1, mid + 1, y);
        }
    }
};
segtree sg;
fenwick <int> sum;
int n, nq;
int ans[nax];
int b[nax];
vector <pair <int, int>> q[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> nq;

    for (int i = 1 ; i <= n; ++ i) {
        cin >> b[i];
        b[i] = i < b[i] ? INF : i - b[i];
    }

    for (int i = 1 ; i <= nq; ++ i) {
        int x, y;
        cin >> x >> y;
        q[x + 1].emplace_back(n - y, i);
    }

    for (int i = n ; i >= 1 ; -- i) {
        sg.update(1, 1, n, i, i, (ll)b[i] - INF);
        while (sg.sg[1] <= 0) {
            int v = sg.find_first_neg(1, 1, n);
            sum.update(v, 1);
            sg.update(1, 1, n, v, v, INF);
            sg.update(1, 1, n, v, n, -1);
        }

        for (const auto &[r, id] : q[i])
            ans[id] = sum.get(i, r);
    }

    for (int i = 1 ; i <= nq ; ++ i) {
        cout << ans[i] << '\n';
    }

}
/*
    Good Luck
        -Lucina
*/