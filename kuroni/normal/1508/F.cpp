#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int N = 25005, Q = 100005, D = 80;

int n, q, a[N], l[Q], r[Q], pos[N], ans[Q];
set<int> se;
vector<pair<int, int>> edges;
vector<int> in, out;
vector<pair<int, int>> l_edge[N], r_edge[N];
vector<array<int, 3>> eve[N];
vector<pair<int, int>> add[N];
vector<pair<int, int>> cur, fin;

struct fenwick_tree {
    int bit[N];

    void init() {
        fill(bit + 1, bit + n + 1, Q);
    }

    void update(int u, int v) {
        for (; u > 0; u -= u & -u) {
            bit[u] = min(bit[u], v);
        }
    }
    
    int query(int u) {
        int ans = Q;
        for (; u <= n; u += u & -u) {
            ans = min(ans, bit[u]);
        }
        return ans;
    }
} bit;

void find_all_edges() {
    auto add_node = [&](int u) {
        auto it = se.insert(u).first;
        if (it != se.begin()) {
            cur.push_back({*prev(it), u});
        }
        if (next(it) != se.end()) {
            cur.push_back({u, *next(it)});
        }
    };
    auto remove_node = [&](int u) {
        se.erase(u);
        auto it = se.lower_bound(u);
        if (it != se.end() && it != se.begin()) {
            cur.push_back({*prev(it), *it});
        }
    };
    auto flush_pair = [&]() {
        for (auto [u, v] : cur) {
            fin.push_back({u, v});
        }
        cur.clear();
    };
    vector<int> que;
    for (int i = 1; i <= q; i++) {
        que.push_back(i);
    }
    sort(que.begin(), que.end(), [](const int u, const int v) {
        return l[u] / D != l[v] / D ? l[u] < l[v] : r[u] < r[v];
    });
    int le = 1, ri = 0;
    for (int ind : que) {
        int cl = l[ind], cr = r[ind];
        while (ri < cr) {
            add_node(a[++ri]);
        }
        while (le > cl) {
            add_node(a[--le]);
        }
        while (ri > cr) {
            remove_node(a[ri--]);
        }
        while (le < cl) {
            remove_node(a[le++]);
        }
        flush_pair();
    }
    edges = vector<pair<int, int>>(fin.begin(), fin.end());
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    in = vector<int>(edges.size(), Q - 1);
    out = vector<int>(edges.size(), Q - 1);
}

void build_events() {
    for (int i = 0; i < edges.size(); i++) {
        auto [u, v] = edges[i];
        int iu = pos[u], iv = pos[v];
        (iv > iu ? r_edge : l_edge)[iu].push_back({iv, i});
    }
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> &le = l_edge[i], &re = r_edge[i];
        reverse(le.begin(), le.end());
        reverse(re.begin(), re.end());
        le.push_back({0, -1});
        re.push_back({n + 1, -1});
        int pl = 0, pr = 0;
        while (pl < le.size() - 1 || pr < re.size() - 1) {
            if (a[le[pl].first] > a[re[pr].first]) {
                int qi = le[pl].second;
                int u = i, v = le[pl].first; // (edge u => v, go to left)
                int t = re[pr].first;
                int vn = le[pl + 1].first;
                eve[v].push_back({u, qi, 0});
                eve[vn].push_back({u, qi, 1});
                eve[v].push_back({t, qi, 1});
                pl++;
            } else {
                int qi = re[pr].second;
                int u = i, w = re[pr].first; // (edge u => w, go to right)
                int t = le[pl].first;
                int wn = re[pr + 1].first;
                eve[u].push_back({w, qi, 0});
                eve[t].push_back({w, qi, 1});
                eve[u].push_back({wn, qi, 1});

                pr++;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        add[l[i]].push_back({r[i], i});
    }
}

void solve() {
    bit.init();
    for (int i = 1; i <= n; i++) {
        for (auto [r, v] : add[i]) {
            bit.update(r, v);
        }
        for (auto [r, i, t] : eve[i]) {
            int &upd = (t == 0 ? in[i] : out[i]);
            upd = min(upd, bit.query(r));
        }
    }
    for (int i = 0; i < edges.size(); i++) {
        ans[in[i]]++;
        ans[out[i]]--;
    }
    for (int i = 1; i <= q; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
    }
    find_all_edges();
    build_events();
    solve();
}