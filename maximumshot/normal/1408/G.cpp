#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int MOD = 998244353;

inline void _add(int& x, int y) {
    if ((x += y) >= MOD)
        x -= MOD;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % MOD;
}

void multiply(vector<int>& a, const vector<int>& b) {
    static vector<int> c;
    c.assign(a.size() + b.size() - 1, 0);
    for (int i = 0; i < (int) a.size(); i++)
        for (int j = 0; j < (int) b.size(); j++)
            _add(c[i + j], _mul(a[i], b[j]));
    swap(a, c);
}

struct DSU {
    int n; // [0, n)
    vector<vector<int>> f;
    vector<int> p, sz, es;

    DSU(int nn) {
        n = nn;
        f.resize(n);
        p.resize(n);
        sz.resize(n);
        es.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            f[i] = {0, 1};
            sz[i] = 1;
            es[i] = 0;
        }
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[y] = x;
            sz[x] += sz[y];
            es[x] += es[y];
            multiply(f[x], f[y]);
        }
        es[x]++;
        if (es[x] == 1ll * sz[x] * (sz[x] - 1) / 2)
            _add(f[x][1], 1);
    }
};

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    vector<tuple<int, int, int>> es;
    es.reserve(n * (n - 1) / 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (i < j)
                es.emplace_back(x, i, j);
        }
    }

    sort(es.begin(), es.end());
    DSU dsu(n);

    for (auto [w, u, v] : es)
        dsu.merge(u, v);

    auto res = dsu.f[dsu.find(0)];
    res.resize(n + 1);

    for (int k = 1; k <= n; k++)
        cout << res[k] << " ";
    cout << "\n";

    return 0;
}