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

unordered_map<int, vector<int>> mem;

vector<int> ask(int n, int r) {
    if (mem.count(r)) {
        return mem[r];
    }
    cout << "? " << r << endl;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    return mem[r] = d;
}

bool verify(vector<pii> edges) {
    cout << "!" << endl;
    for (auto [u, v] : edges)
        cout << u << " " << v << endl;
    return true;
}

int main() {

#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> d = ask(n, 1);
    vector<vector<int>> g(n + 1), on_depth(n + 1);
    for (int i = 1; i <= n; i++) {
        on_depth[d[i]].push_back(i);
    }

    int even = 0, odd = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            odd += (int) on_depth[i].size();
        } else {
            even += (int) on_depth[i].size();
        }
    }

    int s = even < odd ? 0 : 1;
    for (int i = s; i <= n; i += 2) {
        for (int v : on_depth[i]) {
            vector<int> f = ask(n, v);
            for (int to = 1; to <= n; to++) {
                if (f[to] == 1) {
                    g[to].push_back(v);
                    g[v].push_back(to);
                }
            }
        }
    }

    vector<pii> edges;
    edges.reserve(n);
    for (int v = 1; v <= n; v++) {
        for (int to : g[v]) {
            edges.emplace_back(min(v, to), max(v, to));
        }
    }

    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());

    verify(edges);

    return 0;
}