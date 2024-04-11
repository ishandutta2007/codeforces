#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

vector<int> a[nax];
int timer, tin[nax], tout[nax], n, q;

inline bool ancestor (int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int b[nax], dep[nax], par[nax];

void dfs (int nod, int pa) {
    tin[nod] = ++ timer;
    par[nod] = pa;

    for (int i : a[nod]) {
        if (i == pa) continue;
        dep[i] = dep[nod] + 1;
        dfs(i, nod);
    }

    tout[nod] = ++ timer;

}

bool query () {
    int k;
    scanf("%d", &k);

    int deepest = -1;
    int want = -1;

    for (int i = 1 ; i <= k;  ++ i) {
        scanf("%d", b + i);
        if (dep[b[i]] > deepest) {
            deepest = dep[b[i]];
            want = b[i];
        }
    }

    if (want == 1) return true;
    want = par[want];

    for (int i = 1; i <= k ; ++ i) {

        if (ancestor(b[i], want)) continue;
        if (b[i] != 1 && ancestor(par[b[i]], want)) continue;
        if (ancestor(want, b[i]) && dep[b[i]] == deepest + 1) continue;

        return false;

    }

    return true;

}

int main () {

    scanf("%d %d", &n, &q);

    for (int i = 1 ; i < n;  ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0);

    for (; q -- ; ) {
        puts(query () ? "YES" : "NO");
    }

}