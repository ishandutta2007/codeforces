#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

struct DSU {
    vector<int> szs;
    vector<pair<int*, int>> buffer;

    vector<int> p, sz;

    DSU(int n) {
        p.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }

    void checkpoint() {
        szs.push_back((int) buffer.size());
    }

    void rollback() {
        int need_sz = szs.back();
        szs.pop_back();
        while ((int) buffer.size() > need_sz) {
            auto [ptr, val] = buffer.back();
            buffer.pop_back();
            *ptr = val;
        }
    }

    void assign(int* ptr, int val) {
        buffer.emplace_back(ptr, *ptr);
        *ptr = val;
    }

    int find(int x) {
        if (x == p[x])
            return x;
        assign(&p[x], find(p[x]));
        return p[x];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        assign(&p[y], x);
        assign(&sz[x], sz[x] + sz[y]);
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, k;
    cin >> n >> q >> k;

    queue<tuple<int, int, int, int>> edges;
    int ptr = 0;
    vector<int> query(q, -1);
    vector<vector<int>> mt_left(q), mt_right(q);
    vector<pii> to_merge(q, {-1, -1});

    for (int r = 0, iter = 0; iter < q; iter++) { // [l, r), r - l <= k
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (u > v)
                swap(u, v);
            edges.push({r, iter, u, v});
            to_merge[iter] = {u, v};
        } else if (t == 2) {
            int x;
            cin >> x;
            x--;
            query[iter] = x;
        } else {
            r++;
            while (!edges.empty()) {
                auto [l, _iter, u, v] = edges.front();
                if (r - l + 1 <= k)
                    break;
                edges.pop();
                mt_left[iter].push_back(_iter);
                mt_right[_iter].push_back(iter);
            }
        }
    }

    while (!edges.empty()) {
        auto [l, _iter, u, v] = edges.front();
        edges.pop();

        mt_left.emplace_back();
        mt_left[q].push_back(_iter);
        mt_right.emplace_back();
        mt_right[_iter].push_back(q);
        query.push_back(-1);
        to_merge.emplace_back(-1, -1);
        q++;
    }

    DSU dsu(n);

    std::function<void(int, int)> rec = [&](int tl, int tr) {
        int tm = (tl + tr) >> 1;
        dsu.checkpoint();
        for (int i = tm + 1; i <= tr; i++) {
            for (int _iter : mt_left[i]) {
                if (_iter > tl)
                    continue;
                auto [u, v] = to_merge[_iter];
                if (dsu.find(u) != dsu.find(v))
                    dsu.merge(u, v);
            }
        }
        if (tl == tr) {
            if (query[tl] != -1)
                cout << dsu.sz[dsu.find(query[tl])] << "\n";
            dsu.rollback();
        } else {
            rec(tl, tm);
            dsu.rollback();
            dsu.checkpoint();
            for (int i = tl; i <= tm; i++) {
                for (int _iter : mt_right[i]) {
                    if (_iter < tr)
                        continue;
                    auto [u, v] = to_merge[i];
                    if (dsu.find(u) != dsu.find(v))
                        dsu.merge(u, v);
                }
            }
            rec(tm + 1, tr);
            dsu.rollback();
        }
    };

    rec(0, q - 1);

    return 0;
}