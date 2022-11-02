#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

const int maxn = 200100;

int n, m;
vector<int> clause[maxn];
int pos[maxn][2], sze[maxn];
int ans[maxn];

int sgn(int x) { return x<0 ? -1 : x>0 ? 1 : 0; }

bool vis[maxn];

void del(int i, int x) {
    if (sze[i] == 0) return;
    else if (sze[i] == 1) {
        if (abs(pos[i][0]) == x) sze[i] = 0;
    } else if (sze[i] == 2) {
        if (abs(pos[i][1]) == x) sze[i] = 1;
        else if (abs(pos[i][0]) == x) {
            pos[i][0] = pos[i][1];
            sze[i] = 1;
        }
    }
}

void process(int);

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    for (int i : clause[x]) {
        del(abs(i), x);
        process(abs(i));
    }
}

void process(int i) {
    if (sze[i] == 0) return;
    else if (sze[i] == 1) {
        ans[i] = sgn(pos[i][0]);
        sze[i] = 0;
        dfs(abs(pos[i][0]));
    } else if (sze[i] == 2) {
        if (sgn(pos[i][0]) == sgn(pos[i][1])) {
            ans[i] = sgn(pos[i][0]);
            sze[i] = 0;
            dfs(abs(pos[i][0]));
            dfs(abs(pos[i][1]));
        }
    }
}

int other(int a, int x) {
    assert(sze[a] == 2);
    if (abs(pos[a][0]) == x) return abs(pos[a][1]);
    else if (abs(pos[a][1]) == x) return abs(pos[a][0]);
    else assert(0);
}

bool dfs2(int x, int p=0) {
    vis[x] = 1;
    bool ret = 0;
    int s;
    for (int i : clause[x]) {
        int a = abs(i);
        if (a == p) {
            s = sgn(i);
            continue;
        }
        int y = other(a, x);
        if (ret) {
            if (!vis[y]) dfs2(y, a);
            ans[a] = -sgn(i);
        } else if (vis[y]) {
            ret = 1;
            ans[a] = sgn(i);
        } else {
            if (dfs2(y, a)) ret = 1, ans[a] = sgn(i);
        }
    }

    if (!ret) {
        if (!p) {
            cout << "NO";
            exit(0);
        }
        ans[p] = s;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int k; cin >> k;
        clause[i].resize(k);
        for (int j=0; j<k; j++) {
            int x; cin >> x;
            clause[i][j] = x;
            pos[abs(x)][sze[abs(x)]++] = sgn(x)*i;
        }
    }

    for (int i=1; i<=m; i++) process(i);

    for (int i=1; i<=n; i++) {
        vector<int> v;
        for (int j : clause[i]) {
            assert(sze[abs(j)] != 1);
            if (sze[abs(j)]) v.push_back(j);
        }
        clause[i] = v;
    }

    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++) {
        if (clause[i].size() == 0) continue;
        if (!vis[i]) dfs2(i);
    }

    cout << "YES\n";
    for (int i=1; i<=m; i++) {
        if (ans[i] >= 0) cout << 1;
        else cout << 0;
    }
    cout << '\n';
}