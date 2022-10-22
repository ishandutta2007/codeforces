#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<int> fast(int n, int m, int x, vector<int> a, vector<pii> edges) {
    {
        ll S = 0;
        for (int i = 1; i <= n; i++)
            S += a[i];
        S -= 1ll * (n - 1) * x;
        if (S < 0)
            return {};
    }
    vector<int> p(n + 1); iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int v) -> int {
        return p[v] == v ? v : find(p[v]);
    };
    vector<set<int>> E(n + 1);
    for (int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        E[u].insert(i);
        E[v].insert(i);
    }
    vector<ll> A(a.begin(), a.end());
    set<pair<ll, int>> Q;
    for (int v = 1; v <= n; v++)
        Q.insert({A[v], v});
    vector<int> res;
    for (int it = 0; it < n - 1; it++) {
        auto v = (--Q.end())->second;
        v = find(v);
        while (1) {
            int eid = *E[v].begin();
            auto [v1, v2] = edges[eid];
            v1 = find(v1), v2 = find(v2);
            if (v1 == v2) {
                E[v].erase(E[v].begin());
                continue;
            }
            res.push_back(eid + 1);
            if (E[v1].size() < E[v2].size()) swap(v1, v2);
            for (int e : E[v2])
                E[v1].insert(e);
            Q.erase({A[v1], v1});
            Q.erase({A[v2], v2});
            A[v1] = A[v1] + A[v2] - x;
            Q.insert({A[v1], v1});
            p[v2] = v1;
            break;
        }
    }
    return res;
}

void work() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pii> edges(m);
    for (auto& [u, v] : edges)
        cin >> u >> v;
    vector<int> res = fast(n, m, x, a, edges);
    if (res.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto x : res)
            cout << x << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}