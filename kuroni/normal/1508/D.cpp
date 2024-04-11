#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, ind = 0, p[N], pos[N];
vector<int> ve;
vector<pair<int, int>> ans;

struct point {
    int x, y;
    
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    
    point operator-(const point &oth) const {
        return point(x - oth.x, y - oth.y);
    }

    long long operator*(const point &oth) const {
        return 1LL * x * oth.y - 1LL * y * oth.x;
    }
} a[N];

struct dsu {
    int par[N];

    void init() {
        fill(par + 1, par + n + 1, -1);
    }

    int trace(int u) {
        return par[u] < 0 ? u : par[u] = trace(par[u]);
    }

    bool connect(int u, int v) {
        if ((u = trace(u)) == (v = trace(v))) {
            return false;
        }
        if (par[u] > par[v]) {
            swap(u, v);
        }
        par[u] += par[v]; par[v] = u;
        return true;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dsu.init();
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> p[i];
        pos[p[i]] = i;
        dsu.connect(i, p[i]);
        if (p[i] != i) {
            if (ind == 0 || make_pair(a[ind].x, a[ind].y) > make_pair(a[i].x, a[i].y)) {
                ind = i;
            }
            ve.push_back(i);
        }
    }
    if (ind == 0) {
        return cout << 0, 0;
    }
    ve.erase(find(ve.begin(), ve.end(), ind));
    sort(ve.begin(), ve.end(), [](const int u, const int v) {
        return (a[u] - a[ind]) * (a[v] - a[ind]) > 0;
    });
    // cout << "root " << ": " << a[ind].x << " " << a[ind].y << '\n';
    // for (int v : ve) {
    //     cout << a[v].x << " " << a[v].y << '\n';
    // }
    for (int i = 0; i < (int)ve.size() - 1; i++) {
        int u = ve[i], v = ve[i + 1];
        if (dsu.connect(u, v)) {
            ans.push_back({u, v});
            swap(pos[p[u]], pos[p[v]]);
            swap(p[u], p[v]);
        }
    }
    while (p[ind] != ind) {
        int v = p[ind];
        ans.push_back({ind, v});
        swap(pos[p[ind]], pos[p[v]]);
        swap(p[ind], p[v]);
    }
    cout << ans.size() << '\n';
    for (auto [u, v] : ans) {
        cout << u << " " << v << '\n';
    }
}