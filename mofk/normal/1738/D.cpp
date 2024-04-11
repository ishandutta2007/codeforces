#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) cin >> p[i];
        int l = 0;
        for (int i = 1; i <= n; ++i) if (p[i] > i) l = i;
        vector<int> mark(n + 2, 0);
        vector<vector<int>> adj(n + 2, vector<int>());
        for (int i = 1; i <= n; ++i) mark[p[i]] = 1, adj[p[i]].push_back(i);
        int start;
        if (mark[0]) start = 0; else start = n + 1;
        vector<vector<int>> ans;
        while (true) {
            ans.push_back({start});
            mark[start] = ans.size();
            bool found = false;
            for (auto u: adj[start]) if (mark[u]) {
                start = u;
                found = true;
                break;
            }
            if (!found) break;
        }
        for (int i = 1; i <= n; ++i) if (!mark[i]) ans[mark[p[i]] - 1].push_back(i);
        cout << l << '\n';
        for (auto v: ans) for (auto x: v) if (1 <= x && x <= n) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}