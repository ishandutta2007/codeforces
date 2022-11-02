#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 200 * 1000 + 10;

vector<int> g[N];
int n;

vector<int> bfs(int st) {
    vector<int> d(n, N);
    d[st] = 0;
    queue<int> q;
    q.push(st);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int to : g[v])
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
    }
    return d;
}

pii get_diam() {
    auto d = bfs(0);
    int v = max_element(d.begin(), d.end()) - d.begin();
    d = bfs(v);
    return {v, max_element(d.begin(), d.end()) - d.begin()};
}

vector<int> path;
vector<int> cur;
set<int> in_path;

void dfs_path(int v, int par, int goal) {
    cur.push_back(v);
    if (v == goal) {
        path = {cur.begin(), cur.end()};
        in_path = {cur.begin(), cur.end()};
        return;
    }
    for (int to : g[v])
        if (to != par)
            dfs_path(to, v, goal);
    cur.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto p = get_diam();
    auto a = p.first;
    auto b = p.second;
    dfs_path(a, a, b);
    auto da = bfs(a);
    auto db = bfs(b);

    ll ans = 0;
    vector<pair<ll, ll>> ds;
    for (int i = 0; i < n; i++) {
        if (in_path.count(i))
            continue;
        ds.emplace_back(max(da[i], db[i]), i);
    }
    sort(ds.rbegin(), ds.rend());
    vector<int> aa, bb, cc;
    for (auto d : ds) {
        ans += d.first;
        aa.push_back(d.second);
        cc.push_back(d.second);
        if (da[d.second] >= db[d.second])
            bb.push_back(a);
        else
            bb.push_back(b);
    }
    for (int i = 0; i + 1 < path.size(); i++) {
        ans += (int)path.size() - i - 1;
        aa.push_back(path[i]);
        bb.push_back(path.back());
        cc.push_back(path[i]);
    }
    cout << ans << "\n";
    for (int i = 0; i < (int)aa.size(); i++)
        cout << aa[i] + 1 << " " << bb[i] + 1 << " " << cc[i] + 1 << "\n";
}