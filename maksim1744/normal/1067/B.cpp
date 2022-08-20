/*
    24.10.2018 19:56:32
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector< vector< int > > g(n);
    set< int > leaves;
    vector< bool > u(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n < 4) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            leaves.insert(i);
        }
    }
    vector< int > value(n, 0);
    while (leaves.size() > 1) {
        --k;
        set< int > next;
        for (auto& v : leaves) {
            u[v] = true;
            for (auto w : g[v]) {
                if (!u[w]) {
                    next.insert(w);
                    ++value[w];
                }
            }
        }
        for (auto v : next) {
            if (value[v] < 3) {
                cout << "No\n";
                return 0;
            }
            value[v] = 0;
        }
        swap(next, leaves);
    }
    if (k == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}