#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> nxt(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        s.insert(i);
        if (nxt[i] == -1)
            nxt[i] = i + 1;
    }
    vector<int> p(n + 2);
    p[n + 1] = n + 1;
    auto dfs = [&](auto self, int v) -> bool {
        if (p[v])
            return true;
        bool ret = self(self, nxt[v]);
        if (!ret)
            return false;
        auto it = s.lower_bound(p[nxt[v]]);
        if (it == s.begin())
            return false;
        --it;
        p[v] = *it;
        s.erase(it);
        return true;
    };
    for (int i = 1; i <= n; i++) {
        if (!dfs(dfs, i)) {
            cout << "-1\n";
            return;
        }
    }
    stack<int> st;
    st.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (p[i] > p[st.top()])
            st.pop();
        if (st.top() != nxt[i]) {
            cout << "-1\n";
            return;
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}