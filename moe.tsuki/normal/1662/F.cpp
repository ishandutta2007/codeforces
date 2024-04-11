#include <bits/stdc++.h>
using namespace std;

const int maxn = 200025;

struct Segtree {
    set<int> st[maxn * 2];
    int n;
    void insert(int l, int r, int v) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) st[l++].insert(v);
            if (r & 1) st[--r].insert(v);
        }
    }
    vector<int> extract(int p, int vl, int vr) {
        vector<int> ret;
        for (p += n; p; p >>= 1) {
            auto &s = st[p];
            auto itl = s.lower_bound(vl);
            auto itr = s.upper_bound(vr);
            for (auto it = itl; it != itr; ++it)
                ret.push_back(*it);
            s.erase(itl, itr);
        }
        return ret;
    }
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n * 2; i++)
            st[i].clear();
    }
} sgt;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        --a, --b;
        vector<int> l(n), r(n);
        sgt.init(n);
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            l[i] = max(0, i - p);
            r[i] = min(n - 1, i + p);
            sgt.insert(l[i], r[i] + 1, i);
        }
        vector<int> dis(n, -1);
        queue<int> que;
        que.emplace(a);
        dis[a] = 0;
        while (!que.empty()) {
            int i = que.front(); que.pop();
            auto to = sgt.extract(i, l[i], r[i]);
            for (int j: to) {
                if (dis[j] == -1) {
                    dis[j] = dis[i] + 1;
                    que.emplace(j);
                }
            }
        }
        cout << dis[b] << '\n';
    }
    return 0;
}