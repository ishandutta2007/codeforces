#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
using P = pair<int, int>;

struct dsu {
private:
    int _n;
    vector<int> parent_or_size;
public:
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    bool merge(int a, int b) {
        int x = leader(a);
        int y = leader(b);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) {
            swap(x, y);
        }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return true;
    }

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, P>> edges(m);
        for (int i = 0; i < m; ++i) {
            int u, v, s;
            cin >> u >> v >> s;
            --u;
            --v;
            edges[i] = { s, { u, v } };
        }
        sort(edges.begin(), edges.end());
        dsu uf(n);
        long long su = 0;
        int ma = -1;
        int mi = M;
        for (auto& e : edges) {
            if (uf.merge(e.second.first, e.second.second)) {
                su += max(e.first - k, 0);
                ma = max(ma, e.first);
            }
            mi = min(mi, abs(k - e.first));
        }
        if (su > 0) {
            cout << su << '\n';
        }
        else {
            cout << mi << '\n';
        }
    }
    return 0;
}