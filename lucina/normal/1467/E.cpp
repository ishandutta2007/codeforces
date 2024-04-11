#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int LOG = 18;
vector <int> g[nax];
int n;
int a[nax];
vector <int> com;
pair <int, int> last_two[nax];
pair <int, int> first_two[nax];
int tin[nax];
int tout[nax];
int timer;
int ct[nax];
int ans;
int sum[nax];
int dep[nax];
int up[nax][LOG]; /// damn :P I don't want to use lca, but seems like I need to
bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;
    for (int i = LOG - 1 ; i >= 0 ; -- i) {
        if (!ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int all_differ(int x, int y, int z) {
    return x != y && x != z && y != z;
}

void add_first(pair <int, int> &first_two, int nw) {
    if (first_two.first != -1) return ;
    first_two.first = first_two.second;
    first_two.second = nw;
}

bool onpath(int x, int y, int z) {
    int b[3] = {x, y, z};
    sort(b, b + 3, [&](int u, int v) {
            return tin[u] < tin[v];
        });
    if (ancestor(b[0], b[1])) {
        int lc = lca(b[1], b[2]);
        if (!( ancestor(b[0], lc) && b[0] != lc && ancestor(lc, b[1]) && lc != b[1])) return true;
    } else if (ancestor(b[1], b[2])) {
        return true;
    }
    return false;
}


bool add(pair <int, int> &lst_two, int nw) {
    if (nw == lst_two.second) return true;
    bool ok = true;

    if (lst_two.first != -1 && lst_two.second != -1 && all_differ(lst_two.first, lst_two.second, nw)) {
        if (onpath(lst_two.first, lst_two.second, nw)) ok = false;
    }

    lst_two.first = lst_two.second;
    lst_two.second = nw;

    return ok;
}

void dfs_time(int node, int parent) {
    dep[node] = dep[parent] + 1;
    add_first(first_two[a[node]], node);
    tin[node] = ++ timer;
    up[node][0] = parent;

    for (int i = 1 ; i < LOG ; ++ i)
        up[node][i] = up[up[node][i - 1]][i - 1];
    for (int to : g[node]) {
        if (to != parent) dfs_time(to, node);
    }
    tout[node] = ++ timer;
}


void dfs_disjoint(int node, int parent) {
    if (!add(last_two[a[node]], node)) {
        puts("0");
        exit(0);
    }

    for (int to : g[node]) {
        if (to == parent) continue;
        dfs_disjoint(to, node);
        if (!add(last_two[a[node]], node)) {
            puts("0");
            exit(0);
        }
    }
}

void dfs_answer(int node, int parent, int cur) {
    cur += sum[node];
    if (cur == 0) ++ ans;
    for (int to : g[node]) {
        if (to != parent) dfs_answer(to, node, cur);
    }
}

int main() {
    tout[0] = 1e9;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        com.push_back(a[i]);
    }
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }


    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());

    for (int i = 1 ; i <= n ; ++ i) {
        a[i] = lower_bound(com.begin(), com.end(), a[i]) - com.begin();
        ct[a[i]] += 1;
    }

    fill(last_two, last_two + n + 1, make_pair(-1, -1));
    fill(first_two, first_two + n + 1, make_pair(-1, -1));

    dfs_time(1, 0);
    dfs_disjoint(1, 0);

    static bool skip[nax];

    for (int i = 0 ; i < int(com.size()) ; ++ i) {
        if (ct[i] > 1) {
            if (ancestor(first_two[i].first, first_two[i].second)) {
                int far = dep[first_two[i].second] - dep[first_two[i].first] - 1;
                int cur = first_two[i].second;
                for (int j = 0 ; j < LOG ; ++ j)
                    if (far >> j & 1) cur = up[cur][j];
                sum[cur] += 1;
                sum[1] -= 1;
                skip[up[cur][0]] = true;
            }
        }
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (ct[a[i]] > 1 && !skip[i]) {
            sum[i] -= 1;

        }
    }

    dfs_answer(1, 0, 0);
    printf("%d\n", ans);

}