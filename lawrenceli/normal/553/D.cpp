#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 100100;
const ld EPS = 1e-15;

int n, m, k;
bool f[MAXN];
vector<int> adj[MAXN];
int num[MAXN], need[MAXN];
bool vis[MAXN];

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;
    for (int i : adj[cur])
        if (!f[i]) {
            num[i]--;
            if (num[i] < need[i])
                dfs(i);
        }
}

vector<int> ans;

bool check(ld mid, bool b = 0) {
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++) {
        need[i] = ceil(mid*int(adj[i].size()));
        num[i] = 0;
        for (int j : adj[i])
            if (!f[j]) num[i]++;
    }

    for (int i=1; i<=n; i++)
        if (!f[i] && num[i] < need[i]) {
            dfs(i);
        }

    if (b) {
        for (int i=1; i<=n; i++)
            if (!vis[i] && !f[i])
                ans.push_back(i);
    }

    for (int i=1; i<=n; i++)
        if (!vis[i] && !f[i])
            return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;
    for (int i=0; i<k; i++) {
        int x; cin >> x;
        f[x] = 1;
    }

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ld lo = 0, hi = 1;
    while (lo + EPS < hi) {
        ld mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid-EPS;
    }

    check(lo-EPS, 1);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
}