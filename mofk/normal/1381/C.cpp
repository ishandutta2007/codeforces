#include <bits/stdc++.h>

using namespace std;

int n, x, y;
int a[100005];

vector<pair<int, int>> solve(vector<int> freq, int tar) {
    vector<pair<int, int>> ret;
    set<pair<int, int>> st;
    for (int i = 1; i <= n + 1; ++i) if (freq[i]) st.insert({freq[i] * 2, i});
    for (int i = 1; i <= tar; ++i) {
        auto it = --st.end();
        int val = it->second, fr = it->first;
        ret.push_back({val, val});
        --freq[val];
        st.erase(it);
        if (fr > 2) st.insert({fr - 2, val});
    }
    set<pair<int, int>> st2;
    for (int i = 1; i <= n + 1; ++i) if (freq[i]) st2.insert({freq[i], i});
    vector<int> deg = freq;
    for (int i = 1; i <= n + 1; ++i) freq[i] *= 2;
    while (st.size()) {
        auto it = --st.end();
        int u = it->second, fru = it->first;
        st.erase(it);
        if (fru != freq[u]) continue;
        auto jt = st2.begin();
        while (jt->second == u) ++jt;
        int v = jt->second;
        ret.push_back({u, v});
        --freq[u];
        --freq[v];
        --deg[v];
        if (freq[u] > deg[u]) st.insert({freq[u], u});
        if (freq[v] > deg[v]) st.insert({freq[v], v});
        st2.erase(jt);
        if (deg[v]) st2.insert({deg[v], v});
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> x >> y;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> freq(n + 2, 0);
        int mex = 0;
        for (int i = 1; i <= n; ++i) ++freq[a[i]];
        for (int i = 1; i <= n + 1; ++i) if (!freq[i]) mex = i;
        int wildcards = n - y;
        int l = x, r = x + wildcards;
        int mx_fr = *max_element(freq.begin(), freq.end());
        int min_hit = max(0, n - 2 * (n - mx_fr));
        int vals = 0;
        for (int i = 1; i <= n + 1; ++i) vals += !!freq[i];
        int tar = -1;
        for (int i = l; i <= r; ++i) if (i >= min_hit && i != n - 1 && (vals > 2 || i % 2 == n % 2)) tar = i;
        if (tar == -1) {
            cout << "NO" << '\n';
            continue;
        }
        vector<pair<int, int>> ans = solve(freq, tar);
        int excess = tar - x;
        for (int i = 0; i < excess; ++i) ans[i].second = mex;
        for (int i = 0; i < wildcards - excess; ++i) ans[tar + i].second = mex;
        int cnt = 0;
        for (auto z: ans) cnt += z.first == z.second;
        assert(cnt == x);
        vector<int> b(n + 1);
        vector<vector<int>> pos(n + 2, vector<int>());
        for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);
        for (auto z: ans) {
            int u = z.first, v = z.second;
            b[pos[u].back()] = v;
            pos[u].pop_back();
        }
        cout << "YES" << '\n';
        for (int i = 1; i <= n; ++i) cout << b[i] << ' '; cout << '\n';
    }
    return 0;
}