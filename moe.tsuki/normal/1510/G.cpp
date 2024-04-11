#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), dep(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        --p[i];
        dep[i] = dep[p[i]] + 1;
    }
    int x = max_element(dep.begin(), dep.end()) - dep.begin();
    vector<int> chain;
    vector<int> onchain(n);
    for (int y = x; y; y = p[y]) {
        onchain[y] = true;
        chain.push_back(y);
    }
    onchain[0] = true;
    chain.push_back(0);
    reverse(chain.begin(), chain.end());
    assert (chain.size() == dep[x] + 1);
    if (dep[x] + 1 >= k) {
        cout << k - 1 << '\n';
        for (int i = 0; i < k; i++)
            cout << chain[i] + 1 << (i + 1 == k ? '\n' : ' ');
        return;
    }

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
        g[p[i]].push_back(i);
    int rest = k - chain.size();
    vector<int> ans;
    const auto dfs = [&](auto self, int i, int f) -> void {
        if (!onchain[i]) {
            if (rest == 0)
                return;
            --rest;
        }
        // cerr << "i = " << i + 1 << endl;
        ans.push_back(i);
        for (int j: g[i]) {
            if (!onchain[j])
                self(self, j, i);
        }
        for (int j: g[i]) {
            if (onchain[j])
                self(self, j, -1);
        }
        if (f != -1)
            ans.push_back(f);
    };
    dfs(dfs, 0, -1);
    cout << ans.size() - 1 << '\n';
    for (int y: ans) {
        cout << y + 1 << ' ';
    }
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

/*
3
6 2
1 1 2 2 3
6 6
1 1 2 2 3
6 4
1 2 3 4 52
1 2
x = 4

11
1 3 6 3 1 2 5 2 4 2 4 
4
1 2 3 4

 */