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

ll fast(int n, vector<int> p, vector<int> a) {
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
        g[p[i]].push_back(i);
    ll mx = 0;
    std::function<pll(int)> dfs = [&](int v) -> pll {
        if (g[v].empty()) {
            mx = max(mx, 1ll * a[v]);
            return {a[v], 1};
        }
        ll S = 0, C = 0;
        for (int to : g[v]) {
            auto [s, c] = dfs(to);
            S += s;
            C += c;
        }
        mx = max(mx, (S + a[v] + C - 1) / C);
        return {S + a[v], C};
    };
    dfs(1);
    return mx;
}

void read(int& n, vector<int>& p, vector<int>& a) {
    cin >> n;
    p.resize(n + 1);
    a.resize(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void work() {
    int n;
    vector<int> p, a;
    read(n, p, a);

    cout << fast(n, p, a) << "\n";
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