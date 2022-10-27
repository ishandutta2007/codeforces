#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, m;
vector <array <int, 3>> e;
int nq;
int ans[nax];
int qu[nax], qv[nax];
int par[nax];
int sz[nax];
bool even[nax];
bool good_com[nax];

void init_dsu() {
    fill(sz, sz + 1 + n, 1);
    iota(par + 1, par + 1 + n, 1);
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    e.resize(m);
    for (auto &[from, to, cost] : e) {
        scanf("%d %d %d", &from, &to, &cost);
        if (cost % 2 == 0) even[from] = even[to] = true;
    }
    scanf("%d", &nq);
    for (int i = 1 ; i <= nq ; ++ i)
        scanf("%d %d", qu + i, qv + i);
    fill(ans + 1, ans + nq + 1, 2);

    for (int b = 0 ; b < 30 ; ++ b) {
        init_dsu();
        for (auto &[u, v, w] : e) {
            if (w >> b & 1) unite(u, v);
        }
        for (int i = 1 ; i <= nq ; ++ i)
            if (find(qu[i]) == find(qv[i])) ans[i] = 0;

        if (b == 0) continue;


        fill(good_com + 1, good_com + 1 + n, false);

        for (int i = 1 ; i <= n ; ++ i) {
            if (even[i]) good_com[find(i)] = true;
        }

        for (int i = 1 ; i <= nq ; ++ i) {
            if (good_com[find(qu[i])]) {
                ans[i] = min(ans[i], 1);
            }
        }
    }


    for (int i = 1 ; i <= nq ; ++ i)
        printf("%d\n", ans[i]);
}