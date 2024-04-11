#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 300100;

int n, m, d[maxn];
vector<pair<int, int> > adj[maxn];
bool vis[maxn];
vector<int> ans;

int dfs(int v, int p = -1, int pi = -1) {
    vis[v] = true;
    int b = d[v];
    for (auto i : adj[v]) {
        if (vis[i.A]) continue;
        b ^= dfs(i.A, v, i.B);
    }

    if (b) ans.push_back(pi);
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    bool hasneg = false;
    int degsum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (d[i] == -1) hasneg = true;
        else degsum += d[i];
    }

    if (hasneg) {
        for (int i = 1; i <= n; i++) {
            if (d[i] == -1) {
                if (hasneg) {
                    d[i] = (degsum & 1);
                    hasneg = false;
                    degsum += d[i];
                } else d[i] = 0;
            }
        }
    }

    if (degsum % 2 == 1) {
        printf("-1\n");
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(MP(b, i));
        adj[b].push_back(MP(a, i));
    }

    dfs(1);

    printf("%d\n", ans.size());
    for (int i : ans) printf("%d\n", i);
}