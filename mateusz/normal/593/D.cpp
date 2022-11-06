#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m, type, p;
long long c[N];
int rep[N], edgeUp[N], son[N], par[N], depth[N];
bool vis[N];
vector<pair<int, int> > V[N];

void DFS(int w) {
    vis[w] = true;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i].first;
        int in = V[w][i].second;
        if (!vis[u]) {
            son[in] = u;
            par[u] = w;
            edgeUp[u] = in;
            depth[u] = depth[w] + 1;
            DFS(u);
        }
    }
}

int find(int w) {
    return rep[w] = (w == rep[w] ? w : find(rep[w]));
}

void Union(int a, int b) {
    rep[find(a)] = find(b);
}

long long query(int a, int b, long long y) {
    vector<long long> d2;
    while (y >= 1 && d2.size() < 65) {
        a = find(a);
        b = find(b);
        if (a == b) {
            break;
        }
        if (depth[a] >= depth[b]) {
            y /= c[edgeUp[a]];
            a = par[a];
        } else {
            d2.push_back(c[edgeUp[b]]);
            b = par[b];
        }
    }
    if (d2.size() >= 65) {
        return 0;
    }
    for (int i = d2.size() - 1; i >= 0; i--) {
        y /= d2[i];
    }
    return y;
}

int a, b;
long long y;

int main() {

    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c[i];
        V[a].push_back({b, i});
        V[b].push_back({a, i});
    }

    DFS(1);

    for (int i = 1; i <= n; i++) {
        if (c[edgeUp[i]] == 1) {
            rep[i] = par[i];
        } else {
            rep[i] = i;
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> type;
        if (type == 1) {
            cin >> a >> b >> y;
            cout << query(a, b, y) << "\n";
        } else {
            cin >> p >> y;
            c[p] = y;
            if (y == 1) {
                Union(son[p], par[son[p]]);
            }
        }
    }

    return 0;
}