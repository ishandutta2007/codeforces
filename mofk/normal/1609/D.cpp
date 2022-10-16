#include <bits/stdc++.h>

using namespace std;

int n, q;
int dad[1005], sz[1005];

int anc(int u) {
    return dad[u] == u ? u : dad[u] = anc(dad[u]);
}
bool join(int u, int v) {
    u = anc(u), v = anc(v);
    if (u == v) return false;
    dad[v] = u;
    sz[u] += sz[v];
    sz[v] = 0;
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) dad[i] = i, sz[i] = 1;
    int free = 0;
    for (int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;
        if (!join(u, v)) ++free;
        vector<int> s;
        for (int j = 1; j <= n; ++j) if (dad[j] == j) s.push_back(sz[j]);
        sort(s.begin(), s.end(), greater<int>());
        int ans = 0;
        for (int j = 0; j <= free; ++j) ans += s[j];
        ans = min(i, ans - 1);
        cout << ans << endl;
    }
    return 0;
}