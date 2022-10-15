#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct dsu {
    vector<int> p, size;
    multiset<int> sizes;

    dsu(int n) : p(n), size(n, 1), sizes(size.begin(), size.end()) {
        iota(p.begin(), p.end(), 0);
    }

    int get(int x) {
        if (x == p[x]) return x;
        return p[x] = get(p[x]);
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        p[x] = y;
        sizes.erase(sizes.find(size[x]));
        sizes.erase(sizes.find(size[y]));
        size[y] += size[x];
        sizes.insert(size[y]);
        return true;
    }
};

void solve() {
    int n, d;
    cin >> n >> d;
    dsu dsu(n);
    int free = 0;
    int comps = n;
    for (int j = 0; j < d; ++j) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        bool diff = dsu.unite(x, y);
        if (diff) comps--; else free++;
        int ans = -1;
        if (comps <= free + 1) {
            cout << n - 1 << '\n';
            continue;
        }
        auto it = dsu.sizes.end();
        for (int k = 0; k <= free; ++k) {
            ans += *--it;
        }
        cout << ans << '\n';
    }
}