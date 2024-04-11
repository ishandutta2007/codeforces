#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int maxn = 100100;

int n;
vector<int> adj[maxn];

ld dfs(int v, int p = -1) {
    ld ret = 0;
    int num = 0;
    for (int i : adj[v])
        if (i != p) {
            ret += dfs(i, v);
            num++;
        }
    if (num == 0) return 0;
    return ret / num + 1;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << fixed << setprecision(10) << dfs(1) << '\n';
}