#include <bits/stdc++.h>

typedef long long ll;

const int INF = 2e9;
const int mod = 1e9 + 7;

using namespace std;

ll d[200200][5], s[200200], k;

vector<int> g[200200];

void dfs(int v, int p) {
    for(int i = 0; i < k; ++i)
        d[v][i] = 0;
    d[v][0] = 1;
    s[v] = 0;
    for(auto to : g[v]) {
        if(to == p)
            continue;
        dfs(to, v);
        for(int i = 0; i < k; ++i) {
            d[v][(i + 1) % k] += d[to][i];
        }
        s[v] += d[to][0] + s[to];
    }
}

ll ans = 0;

void dfs2(int v, int p, vector<ll> up) {
    ans += s[v];
    vector<ll> tmp = up;
    for(int i = 0; i < k; ++i) {
        tmp[(i + 1) % k] = up[i];
    }
    up = tmp;
    up[k] += up[1 % k];
    ans += up[k];
    for(int i = 0; i < k; ++i)
        up[i] += d[v][i];
    up[k] += s[v];
    for(auto to : g[v]) {
        if(to == p)
            continue;
        for(int i = 0; i < k; ++i) {
            up[(i + 1) % k] -= d[to][i];
        }
        up[k] -= s[to] + d[to][0];
        dfs2(to, v, up);
        for(int i = 0; i < k; ++i) {
            up[(i + 1) % k] += d[to][i];
        }
        up[k] += s[to] + d[to][0];
    }
}


void solve() {
    int n;
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    vector<ll> up(k + 1, 0);
    dfs2(0, -1, up);
    cout << ans / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}