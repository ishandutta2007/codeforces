#include <bits/stdc++.h>

using namespace std;

const int maxN = 10200;

struct edge {
    int to, fl, lnk;
};
vector<edge> ed[maxN];
int o[maxN];
int hg[maxN];
int n, m;
int st[maxN];
int a[maxN];
int b[maxN];
void add_edge(int x, int y, int fl, int lnk) {
    ed[x].push_back((edge){y, fl, lnk});
}
void build(int st) {
    int l = 1;
    int sz = 1;
    hg[st] = 0;
    o[l] = 0;
    while (l <= sz) {
        int x = o[l];
        for (int j = 0; j < ed[x].size(); j++) {
            if (ed[x][j].fl == 0) continue;
            int to = ed[x][j].to;
            if (hg[to] <= hg[x] + 1) continue;
            sz++;
            o[sz] = to;
            hg[to] = hg[x] + 1;
        }
        l++;
    }
}
int dfs(int x, int y) {
    if (x == n + m + 1) return y;
    for (; st[x] < ed[x].size(); st[x]++) {
        int to = ed[x][st[x]].to;
        int j = st[x];
        if (hg[to] != hg[x] + 1) continue;
        if (ed[x][j].fl == 0) continue;
        int p = dfs(to, min(y, ed[x][j].fl));
        if (p == 0) continue;
        ed[x][j].fl -= p;
        ed[to][ed[x][j].lnk].fl += p;
        return p;
    }
    return 0;
}
bool check(int l) {
    for (int i = 0; i <= n + m + 1; i++) ed[i].clear();
    for (int i = 1; i <= m; i++) {
        add_edge(i, a[i] + m, 1, ed[a[i] + m].size());
        add_edge(a[i] + m, i, 0, ed[i].size() - 1);
        add_edge(i, b[i] + m, 1, ed[b[i] + m].size());
        add_edge(b[i] + m, i, 0, ed[i].size() - 1);
    }
    for (int i = 1; i <= m; i++) {
        add_edge(0, i, 1, ed[i].size());
        add_edge(i, 0, 0, ed[0].size() - 1);
    }
    for (int i = m + 1; i <= n + m; i++) {
        add_edge(i, n + m + 1, l, ed[n + m + 1].size());
        add_edge(n + m + 1, i, 0, ed[i].size() - 1);
    }
    int flow = 0;

    while (1) {
        for (int i = 0; i <= n + m + 1; i++) st[i] = 0, hg[i] = n + m + 3;
        build(0);
        if (hg[n + m + 1] == n + m + 3) break;
        int push = dfs(0, 1e9);
        while (push != 0) {
            flow += push;
            push = dfs(0, 1e9);
        }
    }

    if (flow == m) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];

    }
    int l = 0;
    int r = n - 1;
    while (r - l > 0) {
        int mid = (r + l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    check(l);
    cout << l << "\n";
    for (int i = 1; i <= m; i++) {
        int ans = 0;
        for (int j = 0; j < ed[i].size(); j++) {
            if (ed[i][j].fl == 0 && ed[i][j].to > m) {
                ans = ed[i][j].to - m;
                break;
            }
        }
        if (ans == a[i]) cout << a[i] << " " << b[i] << "\n";
        else cout << b[i] << " " << a[i] << "\n";
    }
    return 0;
}