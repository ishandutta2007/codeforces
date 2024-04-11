#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 300 * 1000 + 10;

map<vector<int>, int> id;
vector<int> at[N];
vector<int> g[N];
vector<int> gr[N];
int col[N];
int comp[N];
int n, m;
bool used[N];
ll cnt[N];

pii make_edge(int a, int b) {
    if (a > b)
        swap(a, b);
    return {a, b};
}

void dfs(int v, int c) {
    used[v] = true;
    for (int x : at[v]) {
        col[x] = c;
        cnt[c]++;
    }
    for (int to : gr[v])
        if (!used[to])
            dfs(to, c + 1);
}

int mabs(int a) {
    return a > 0 ? a : -a;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        g[i].push_back(i);
        sort(g[i].begin(), g[i].end());
    }
    for (int i = 0; i < n; i++) {
        if (!id.count(g[i])) {
            int sz = id.size();
            id[g[i]] = sz;
        }
        comp[i] = id[g[i]];
        at[comp[i]].push_back(i);
    }
    set<pii> was;
    for (int i = 0; i < n; i++)
        for (int to : g[i]) {
            int a = comp[i];
            int b = comp[to];
            if (a >= b || was.count(make_edge(a, b)))
                continue;
            was.insert(make_edge(a, b));
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
    for (int i = 0; i < id.size(); i++)
        if (gr[i].size() <= 1) {
            dfs(i, 1);
            break;
        }
    bool bad = false;
    for (int i = 0; i < n; i++)
        if (!col[i])
            bad = true;
    ll want_edges = 0;
    for (int i = 1; i <= n; i++) {
        want_edges += cnt[i] * 1ll * (cnt[i] - 1) / 2;
        want_edges += cnt[i] * 1ll * cnt[i + 1];
    }
    if (want_edges != m || bad) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int to : g[i])
            if (mabs(col[i] - col[to]) > 1) {
                cout << "NO" << endl;
                return 0;
            }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        cout << col[i] << " ";
    cout << endl;
}