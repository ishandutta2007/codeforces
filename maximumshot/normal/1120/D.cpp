#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n;
int c[N];
vector<int> g[N];
int degree[N];
int parent[N];
set<int> mns[N];
int mn[N];
int leafs[N];

void dfs(int v, int par = -1) {
    parent[v] = par;
    if (par != -1) {
        degree[par]++;
    }
    {
        int i = 0;
        while (i < (int)g[v].size() && g[v][i] != par) i++;
        if (i < (int)g[v].size()) {
            swap(g[v][i], g[v][(int)g[v].size() - 1]);
            g[v].pop_back();
        }
    }
    for (int to : g[v]) {
        dfs(to, v);
    }
    if (g[v].empty() && par != -1) {
        leafs[par]++;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    set<pii> vs;
    set<int> ans;
    ll cost = 0;

    for (int v = 1; v <= n; v++) {
        if (degree[v] == 0) {
            mn[v] = c[v];
            mns[v] = {v};
        }
        if (degree[v] > 0 && leafs[v] == degree[v]) {
            vs.insert({degree[v], v});
        }
    }

    while (!vs.empty()) {
        int v = vs.begin()->second;
        vs.erase(vs.begin());
        if (degree[v] == 1) {
            int son = g[v][0];
            if (c[v] < mn[son]) {
                mn[v] = c[v];
                mns[v] = {v};
            } else if (c[v] > mn[son]) {
                mn[v] = mn[son];
                swap(mns[son], mns[v]);
            } else {
                mn[v] = mn[son];
                swap(mns[son], mns[v]);
                mns[v].insert(v);
            }
            if (parent[v] != -1) {
                leafs[parent[v]]++;
                if (leafs[parent[v]] == degree[parent[v]]) {
                    vs.insert({degree[parent[v]], parent[v]});
                }
            }
            continue;
        }
        int mx = -1;
        int cn = 0;
        int fr = -1;
        for (int son : g[v]) {
            if (mx < mn[son]) {
                mx = mn[son];
                cn = 1;
                fr = son;
            } else if (mx == mn[son]) {
                cn++;
            }
        }
        if (cn > 1) {
            for (int son : g[v]) {
                for (int x : mns[son]) {
                    ans.insert(x);
                }
            }
        } else {
            for (int son : g[v]) {
                if (mn[son] == mx) continue;
                for (int x : mns[son]) {
                    ans.insert(x);
                }
            }
        }
        for (int son : g[v]) {
            if (son == fr) continue;
            cost += mn[son];
        }
        for (int i = 0; i < (int)g[v].size(); i++) {
            if (g[v][i] == fr) {
                swap(g[v][i], g[v][0]);
                while ((int)g[v].size() > 1) {
                    g[v].pop_back();
                }
                break;
            }
        }
        int son = g[v][0];
        if (c[v] < mn[son]) {
            mn[v] = c[v];
            mns[v] = {v};
        } else if (c[v] > mn[son]) {
            mn[v] = mn[son];
            swap(mns[son], mns[v]);
        } else {
            mn[v] = mn[son];
            swap(mns[son], mns[v]);
            mns[v].insert(v);
        }
        if (parent[v] != -1) {
            leafs[parent[v]]++;
            if (leafs[parent[v]] == degree[parent[v]]) {
                vs.insert({degree[parent[v]], parent[v]});
            }
        }
    }

    cost += mn[1];

    for (int x : mns[1]) {
        ans.insert(x);
    }

    cout << cost << " " << (int)ans.size() << "\n";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}