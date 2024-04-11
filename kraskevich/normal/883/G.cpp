#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 300 * 1000 + 10;

struct Edge {
    int a;
    int b;
    int id;

    Edge(int a, int b, int id): a(a), b(b), id(id) {}
};

string ans;
vector<Edge> g[N];
bool was[N];
int cnt;

void dfs1(int v) {
    cnt++;
    was[v] = true;
    for (const auto& e : g[v]) {
        int to = e.a;
        if (to == v)
            to = e.b;
        if (was[to])
            continue;
        dfs1(to);
        if (e.id != -1 && to == e.a)
            ans[e.id] = '-';
    }
}

void dfs2(int v) {
    cnt++;
    was[v] = true;
    for (const auto& e : g[v]) {
        int to = e.a;
        if (to == v)
            to = e.b;
        if (was[to])
            continue;
        if (e.id == -1)
            dfs2(to);
        else {
            if (to == e.b)
                ans[e.id] = '-';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int st;
    cin >> st;
    --st;
    int tot = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> c >> a >> b;
        --a;
        --b;
        if (c == 1) {
            g[a].emplace_back(a, b, -1);
        } else {
            g[a].emplace_back(a, b, tot);
            g[b].emplace_back(a, b, tot);
            tot++;
        }
    }
    ans.assign(tot, '+');
    dfs1(st);
    cout << cnt << "\n" << ans << "\n";
    
    ans.assign(tot, '+');
    cnt = 0;
    fill(was, was + n, false);
    dfs2(st);
    cout << cnt << "\n" << ans << "\n";
}