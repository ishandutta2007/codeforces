#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v[max_n];
vector<int> g[max_n];
int n, m;
ll w[max_n];
bool col[max_n];
bool vis[max_n];
int root = -1;

void dfs1(int cur, int pr) {
    if (root != -1) {
        return;
    }
    vis[cur] = 1;
    for (int to : v[cur]) {
        if (to == pr) {
            continue;
        }
        if (vis[to]) {
            root = cur;
            return;
        }
        dfs1(to, cur);
    }
}

int dfs2(int cur, int pr) {
    vis[cur] = 1;
    for (int to : v[cur]) {
        if (to == pr) {
            continue;
        }
        if (vis[to]) {
            col[cur] = 1;
        } else {
            col[cur] |= dfs2(to, cur);
        }
    }
    return col[cur];
}

ll ans = 0;
void dfs(int cur, int pr, ll sum) {
    sum += w[cur];
    ans = max(ans, sum);
    vis[cur] = 1;
    for (int to : g[cur]) {
        if (to == pr) {
            continue;
        }
        if (vis[to]) {
            exit(228);
        }
        dfs(to, cur, sum);
    }
}

void add(int from, int to) {
    if (from < to) {
        g[from].PB(to);
        g[to].PB(from);
    }
}

vector<int> path;
bool fnd = 0;
ll res = 0;

void dfs3(int cur, int pr) {
    if (fnd) {
        return;
    }
    path.PB(cur);
    if (cur == root) {
        ans = 0;
        for (int ver : path) {
            res += w[ver];
            w[ver] = 0;
        }
        fnd = 1;
        return;
    }
    for (int to : g[cur]) {
        if (to == pr) {
            continue;
        }
        dfs3(to, cur);
        if (fnd) {
            return;
        }
    }
    path.pop_back();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    int s;
    cin >> s;
    --s;
    dfs1(0, -1);
    if (root == -1) {
        for (int i = 0; i < n; ++i) {
            for (int j : v[i]) {
                add(i, j);
            }
        }
        memset(vis,0, sizeof(vis));
        dfs(s, -1, 0);
        cout << ans << endl;
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    col[root] = 1;
    dfs2(root, -1);
    for (int i = 0; i < n; ++i) {
        for (int j : v[i]) {
            if (col[i] && col[j]) {
                continue;
            }
            if (col[i]) {
                add(root, j);
            } else if (col[j]) {
                add(i, root);
            } else {
                add(i, j);
            }
        }
        if (i != root && col[i]) {
            w[root] += w[i];
        }
    }
    memset(vis,0, sizeof(vis));
    if (col[s]) {
        s = root;
    }
    dfs(s, -1, 0);
    if (s == root) {
        cout << ans << endl;
        return 0;
    }
    dfs3(s, -1);
    ll ANS = ans;
    ans = 0;
    memset(vis, 0, sizeof(vis));
    dfs(root, -1, 0);
    ANS = max(ANS, ans + res);
    cout << ANS << endl;
    return 0;
}