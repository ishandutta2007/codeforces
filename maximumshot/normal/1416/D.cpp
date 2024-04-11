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

struct Event {
    int type = 0; // 0 - assign, 1 - insert, 2 - extract

    int* pos = nullptr;
    int val = 0;
    int id = -1;

    int insert_to = 0;
};

vector<Event> events;

struct DSU {
    int n; // [1, n]
    vector<int> p, sz;
    vector<multiset<pii>> vs;
    vector<int> deleted;

    DSU(int nn, const vector<int>& a) {
        n = nn;
        p.resize(n + 1);
        sz.resize(n + 1);
        vs.resize(n + 1);
        deleted.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
            vs[i].insert({a[i], i});
            deleted[i] = 0;
        }
    }

    int find(int x) {
        return x == p[x] ? x : find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        events.push_back({0, &p[y], p[y]}); // p[y] = x;
        p[y] = x;
        events.push_back({0, &sz[x], sz[x]}); // sz[x] += sz[y];
        sz[x] += sz[y];
        for (auto v : vs[y]) {
            vs[x].insert(v);
            events.push_back({1, nullptr, v.first, v.second, x});
        }
    }

    int extract(int x) {
        x = find(x);
        while (!vs[x].empty() && deleted[(--vs[x].end())->second])
            vs[x].erase(--vs[x].end());
        if (vs[x].empty())
            return 0;
        auto [res, id] =  *(--vs[x].end());
        deleted[id] = 1;
        return res;
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<pii> es(m);
    for (int i = 0; i < m; i++)
        cin >> es[i].first >> es[i].second;

    vector<pii> qs(q);
    vector<int> have(m, 1);
    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 2) {
            x--;
            have[x] = 0;
        }
        qs[i] = {t, x};
    }

    DSU dsu(n, a);

    for (int i = 0; i < m; i++) {
        if (have[i]) {
            auto [u, v] = es[i];
            dsu.merge(u, v);
        }
    }

    vector<int> szs;
    szs.push_back((int) events.size());

    for (int i = q - 1; i >= 0; i--) {
        auto [t, x] = qs[i];
        if (t == 2) {
            auto [u, v] = es[x];
            dsu.merge(u, v);
            szs.push_back((int) events.size());
        }
    }

    for (int i = 0; i < q; i++) {
        auto [t, x] = qs[i];
        if (t == 1) {
            cout << dsu.extract(x) << "\n";
        } else {
            szs.pop_back();
            int need_sz = szs.back();
            while ((int) events.size() > need_sz) {
                auto event = events.back();
                events.pop_back();
                if (event.type == 0) { // assign
                    *event.pos = event.val;
                } else if (event.type == 1) { //
                    dsu.vs[event.insert_to].erase({event.val, event.id});
                }
            }
        }
    }

    return 0;
}