#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

vector<int> g[300300];
vector<pair<int, int> > e;
int c[300300], st[300300];

set<pair<int, int> > forb;

void dfs(int v, int p) {
    st[v] = 1;
    for(auto to: g[v]) {
        if(!st[to])
            dfs(to, v);
    }
    if(c[v]) {
        forb.insert({v, p});
        forb.insert({p, v});
        c[v] = 0;
        if(p != -1)
            c[p] ^= 1;
    }
}

void solve() {
    int n, m, ones = 0, minus = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
        if(c[i] == 1)
            ones ^= 1;
        if(c[i] == -1)
            minus = 1;
    }
    if(ones && !minus) {
        puts("-1");
        return;
    }
    if(ones) {
        for(int i = 0; i < n; ++i) {
            if(c[i] == -1) {
                if(minus)
                    c[i] = 1, minus = 0;
                else
                    c[i] = 0;
            }
        }
    } else {
        for(int i = 0; i < n; ++i)
            if(c[i] == -1)
                c[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        e.push_back({a, b});
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; ++i)
        c[i] ^= (g[i].size() % 2);
    dfs(0, -1);
    vector<int> ans;
    for(int i = 0; i < m; ++i) {
        if(forb.find(e[i]) == forb.end()) {
            ans.push_back(i + 1);
        } else {
            forb.erase(e[i]);
            forb.erase({e[i].second, e[i].first});
        }
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}