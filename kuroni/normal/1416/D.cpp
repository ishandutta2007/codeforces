#include <bits/stdc++.h>
using namespace std;

const int N = 200005, M = 300005, Q = 500005;

int n, m, q, p[N], u[M], v[M], pos[N], ind[N];
int t[Q], que[Q], brk[Q];
bool chk[M], vis[N];
vector<int> adj[N];

struct component {
    multiset<int, greater<int>> ele, ch;
    int par, ind, sz;

    component(int _ind) {
        ele = {0}; ch = {};
        sz = 0; par = ind = _ind;
    }

    int parent();
};
vector<component> com;

int component::parent() {
    return par == ind ? ind : com[par].parent();
}

void DFS(int u) {
    pos[u] = com.size() - 1;
    vis[u] = true;
    com.back().sz++;
    com.back().ele.insert(p[u]);
    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

void remove(int cp, int u) {
    int prv = -1, cur = -1;
    while (true) {
        int nprv = *com[cp].ch.begin();
        if (prv == -1) {
            prv = *com[cp].ele.begin();
            com[cp].ele.erase(u);
        }
        if (cur == -1) {
            cur = *com[cp].ele.begin();
        }
        com[cp].ch.erase(com[cp].ch.find(prv));
        com[cp].ch.insert(cur);
        int ncur = *com[cp].ch.begin();
        prv = nprv; cur = ncur;
        if (com[cp].par == com[cp].ind) {
            break;
        }
        cp = com[cp].par;
    }
}

void remove_edge(int cp) {
    int prv = *com[cp].ch.begin(), cur = -1;
    swap(cp, com[cp].par);
    while (true) {
        int nprv = *com[cp].ch.begin();
        com[cp].ch.erase(prv);
        if (cur != -1) {
            com[cp].ch.insert(cur);
        }
        int ncur = *com[cp].ch.begin();
        prv = nprv; cur = ncur;
        if (com[cp].par == com[cp].ind) {
            break;
        }
        cp = com[cp].par;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        ind[p[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> t[i] >> que[i];
        if (t[i] == 2) {
            chk[que[i]] = true;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!chk[i]) {
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            com.push_back(component((int)com.size()));
            DFS(i);
        }
    }
    for (component& v : com) {
        v.ch.insert(*v.ele.begin());
    }
    for (int i = q; i >= 1; i--) {
        if (t[i] == 2) {
            int tu = com[pos[u[que[i]]]].parent(), tv = com[pos[v[que[i]]]].parent();
            if (tu != tv) {
                if (com[tu].sz < com[tv].sz) {
                    swap(tu, tv);
                }
                brk[i] = tv;
                com[tv].par = tu;
                com[tu].sz += com[tv].sz;
                com[tu].ch.insert(*com[tv].ch.begin());
            } else {
                brk[i] = -1;
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        if (t[i] == 1) {
            int tu = com[pos[que[i]]].parent();
            int nod = ind[*com[tu].ch.begin()];
            cout << p[nod] << '\n';
            if (nod != 0) {
                remove(pos[nod], p[nod]);
            }
        } else if (brk[i] != -1) {
            remove_edge(brk[i]);
        }
    }
}