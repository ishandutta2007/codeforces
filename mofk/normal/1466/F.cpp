#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, maxn = 5e5 + 5;

int n, m;
int u[maxn], v[maxn];
int dad[maxn];
int on[maxn];

int anc(int u) {
    if (u == dad[u]) return u;
    return dad[u] = anc(dad[u]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) dad[i] = i;
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        int k, u, v;
        cin >> k;
        if (k == 1) {
            cin >> u;
            int p = anc(u);
            if (!on[p]) {
                on[p] = 1;
                ans.push_back(i);
            }
        }
        else {
            cin >> u >> v;
            int p = anc(u), q = anc(v);
            if (p == q) continue;
            if (on[p] && on[q]) continue;
            dad[q] = p;
            on[p] |= on[q];
            on[q] = 0;
            ans.push_back(i);
        }
    }
    int sz = 1;
    for (int i = 0; i < ans.size(); ++i) sz = 2 * sz % mod;
    cout << sz << ' ' << ans.size() << endl;
    for (auto x: ans) cout << x << ' '; cout << endl;

    return 0;
}