#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int INF = (int) 1e9;
const int N = 100 * 1000 + 10;
const int L = 20;

vi g[N];
int tin[N];
int tout[N];
int go[N][L];
int rev[4 * N];
int timer;

ll dp[N][2];
int par[N];
vi tree[N];
set<int> important;
set<int> seen;
set<int> seen_tin;

void dfs(int v, int p) {
    tin[v] = timer++;
    rev[tin[v]] = v;
    go[v][0] = p;
    for (int l = 1; l < L; l++)
        go[v][l] = go[go[v][l - 1]][l - 1];
    for (int to : g[v])
        if (to != p)
            dfs(to, v);
    tout[v] = timer++;
}

void calc(int v) {
    ll sum0 = 0;
    ll sum1 = 0;
    ll max_delta = 0;
    for (int to : tree[v]) {
        calc(to);
        if (go[to][0] != v)
            dp[to][0] = min(dp[to][0], dp[to][1] + 1);
        sum0 += dp[to][0];
        sum1 += dp[to][1];
        max_delta = max(max_delta, dp[to][0] - dp[to][1]);  
    }
    if (important.find(v) == important.end()) {
        dp[v][0] = min(sum0, sum1 + 1);
        dp[v][1] = sum0 - max_delta;
    } else {
        dp[v][0] = INF;
        dp[v][1] = sum0;
    }
    dp[v][0] = min(dp[v][0], INF + 0ll);
    dp[v][1] = min(dp[v][1], dp[v][0]);
}

void add(int v) {
    if (seen.find(v) != seen.end())
        return;
    seen.insert(v);
    seen_tin.insert(tin[v]);
}

bool isEmpty(int v) {
    auto it = seen_tin.lower_bound(tin[v]);
    return it == seen_tin.end() || (*it) > tout[v];
}

int solve(const vi& a) {
    seen_tin.clear();
    seen.clear();
    important.clear();
    for (int x : a) 
        important.insert(x);
    for (int x : a)
        if (go[x][0] != x && important.find(go[x][0]) != important.end())
            return -1;
    int root = a[0];
    add(a[0]);
    for (int i = 1; i < a.size(); i++) {
        int x = a[i];
        if (seen.find(x) != seen.end())
            continue;
        int y = x;
        for (int l = L - 1; l >= 0; l--) 
            if (isEmpty(go[y][l]))
                y = go[y][l];
        if (isEmpty(y))
            y = go[y][0];
        par[x] = y;
        if (seen.find(y) == seen.end()) {
            int split = rev[*seen_tin.lower_bound(tin[y])];
            par[y] = par[split];
            par[split] = y;
            if (par[y] == -1)
                root = y;
            add(y);        
        }
        add(x);
    }
    for (int x : seen)
        if (par[x] != -1)
            tree[par[x]].push_back(x);
    calc(root);
    for (int x : seen) {
        tree[x].clear();
        par[x] = -1;
    }
    return min(dp[root][0], dp[root][1]);
}


int main() {
    ios_base::sync_with_stdio(0);
    fill(par, par + N, -1);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);
    int q;
    cin >> q;
    while (q--) {
        int s;
        cin >> s;
        vector<int> v(s);
        for (int i = 0; i < s; i++) {
            cin >> v[i];
            v[i]--;
        }
        cout << solve(v) << "\n";
    }
    return 0;
}