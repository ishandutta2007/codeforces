#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <cassert>

using namespace std;

const int maxn = 305;
const int maxm = maxn * maxn * 2;

int n, v, m;
bool mat[maxn][maxn];
int va[maxn], vb[maxn];

bool vis[maxn], used[maxn];
int nums[maxn], cnt;
vector<int> adj[maxn];

int ax[maxm], ay[maxm], ad[maxm], sze;

void dfs(int cur) {
    nums[cnt++] = cur;
    vis[cur] = 1;

    for (int i = 0; i < n; i++)
        if (mat[cur][i] && !vis[i]) {
            adj[cur].push_back(i);
            adj[i].push_back(cur);
            dfs(i);
        }
}

void trans(int a, int b, int d) {
    ax[sze] = a, ay[sze] = b, ad[sze] = d;
    sze++;
    va[a] -= d;
    va[b] += d;
    assert(va[a] >= 0 && va[b] <= v);
}

void dfs2(int cur, int p, bool b) {
    for (int i : adj[cur])
        if (i != p)
            dfs2(i, cur, b);

    for (int i : adj[cur])
        if (i != p) {
            if (!b) trans(i, cur, min(va[i], v - va[cur]));
            else trans(cur, i, min(va[cur], v - va[i]));
        }
}

void go(int x) {
    used[x] = 1;
    if (va[x] < vb[x]) {
        dfs2(adj[x][0], x, 0);
        trans(adj[x][0], x, vb[x] - va[x]);
    } else {
        dfs2(adj[x][0], x, 1);
        trans(x, adj[x][0], va[x] - vb[x]);
    }

    int y = adj[x][0];
    for (int i = 0; i < adj[y].size(); i++)
        if (adj[y][i] == x) {
            adj[y].erase(adj[y].begin() + i);
            break;
        }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> v >> m;
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n; i++) cin >> vb[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = mat[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            cnt = 0;
            dfs(i);

            long long sa = 0, sb = 0;
            for (int j = 0; j < cnt; j++)
                sa += va[nums[j]], sb += vb[nums[j]];

            if (sa != sb) {
                cout << "NO\n";
                return 0;
            }

            for (int j = 0; j < cnt; j++)
                for (int k = 0; k < cnt; k++)
                    if (!used[nums[k]] && adj[nums[k]].size() == 1)
                        go(nums[k]);
        }

    cout << sze << '\n';
    for (int i = 0; i < sze; i++)
        cout << ax[i] + 1 << ' ' << ay[i] + 1 << ' ' << ad[i] << '\n';
}