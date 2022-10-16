#include <bits/stdc++.h>

using namespace std;

int n, p;
int a[500005], b[500005];
vector <vector <int> > adj;
vector <int> ans;
bool seen[500005];

void dfs(int u, int laste) {
    while (adj[u].size()) {
        int e = adj[u].back();
        adj[u].pop_back();
        if (seen[e]) continue;
        seen[e] = true;
        int v = (a[e] % p) ^ (b[e] % p) ^ u;
        dfs(v, e);
    }
    if (laste != -1) ans.push_back(laste);
}

void gogo(int x) {
    p = 1 << x;
    adj.assign(p, vector <int>());
    vector <int> deg(p, 0);
    for (int i = 1; i <= n; ++i) {
        int u = a[i] % p, v = b[i] % p;
        adj[u].push_back(i);
        adj[v].push_back(i);
        ++deg[u], ++deg[v];
    }
    for (int i = 0; i < p; ++i) if (deg[i] % 2 == 1) return;
    for (int i = 1; i <= n; ++i) seen[i] = false;
    for (int i = 0; i < p; ++i) if (deg[i] > 0) {
        ans.clear();
        dfs(i, -1);
        if (ans.size() == n) {
            cout << x << endl;
            reverse(ans.begin(), ans.end());
            int last = i;
            for (int j = 0; j < n; ++j) {
                int f = ans[j];
                if (a[f] % p == last) {
                    cout << 2 * f - 1 << ' ' << 2 * f << ' ';
                    last = b[f] % p;
                }
                else {
                    assert(b[f] % p == last);
                    cout << 2 * f << ' ' << 2 * f - 1 << ' ';
                    last = a[f] % p;
                }
            }
            assert(last == i);
            exit(0);
        }
        else return;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];

    for (int i = 20; i >= 1; --i) gogo(i);
    cout << 0 << endl;
    for (int i = 1; i <= n * 2; ++i) cout << i << ' ';
    cout << endl;
    return 0;
}