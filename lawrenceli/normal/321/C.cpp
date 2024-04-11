#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <ios>

using namespace std;

#define repi(i, n) for (__typeof(n.begin()) i = n.begin(), _##i = n.end(); i != _##i; i++)

const int MAXN = 100100;

int n, ans[MAXN];
set<int> adj[MAXN];
int sub[MAXN], sze;

void dfs1(int cur, int p) {
    sub[cur] = 1;
    repi(i, adj[cur]) {
        int nxt = *i;
        if (nxt == p) continue;
        dfs1(nxt, cur);
        sub[cur] += sub[nxt];
    }
}

int dfs2(int cur, int p) {
    repi(i, adj[cur]) {
        int nxt = *i;
        if (nxt == p) continue;
        if (sub[nxt] > sze / 2) return dfs2(nxt, cur);
    }
    return cur;
}

void go(int cur, int num) {
    dfs1(cur, cur);
    sze = sub[cur];
    cur = dfs2(cur, cur); //centroid
    ans[cur] = num;
    repi(i, adj[cur]) {
        int nxt = *i;
        adj[nxt].erase(cur);
        go(nxt, num+1);
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    go(0, 0);

    for (int i=0; i<n; i++)
        cout << char(ans[i] + 'A') << ' ';

    cout << '\n';

    return 0;
}