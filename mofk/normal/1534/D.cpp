#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> ans;
vector<int> ask(int u) {
    cout << "? " << u << endl;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    return v;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> d = ask(1);
    vector<int> a, b;
    for (int i = 2; i <= n; ++i) if (d[i] % 2 == 0) a.push_back(i); else b.push_back(i);
    for (int i = 2; i <= n; ++i) if (d[i] == 1) ans.push_back({1, i});
    if (a.size() > b.size()) swap(a, b);
    for (auto u: a) {
        vector<int> du = ask(u);
        for (int v = 2; v <= n; ++v) if (du[v] == 1) ans.push_back({u, v});
    }
    assert(ans.size() == n - 1);
    cout << "!" << endl;
    for (auto x: ans) cout << x.first << ' ' << x.second << endl;
    return 0;
}