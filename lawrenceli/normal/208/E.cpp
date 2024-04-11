#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

const int MAXN = 100100;
const int MAXLG = 17;

int n, jump[MAXN][MAXLG], dep[MAXN];
vector<int> adj[MAXN];
vector<int> root;
int ent[MAXN], exi[MAXN], cnt;
vector<int> nodes[MAXN]; //nodes at depth k

void dfs(int cur) {
    ent[cur] = cnt++;
    if (jump[cur][0] != -1)
        dep[cur] = dep[jump[cur][0]] + 1;
    nodes[dep[cur]].push_back(cur);
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        dfs(nxt);
    }
    exi[cur] = cnt++;
}

int anc(int cur, int p) {
    for (int i=0; i<MAXLG; i++)
        if (p & 1<<i)
            cur = jump[cur][i];
    return cur;
}

bool cmp1(int a, int b) {
    return ent[a] < ent[b];
}

bool cmp2(int a, int b) {
    return ent[b] > exi[a];
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> jump[i][0]; jump[i][0] --;
        if (jump[i][0] == -1) root.push_back(i);
        else adj[jump[i][0]].push_back(i);
    }

    for (int i=0; i<root.size(); i++)
        dfs(root[i]);

    for (int k=1; k<MAXLG; k++)
        for (int i=0; i<n; i++)
            jump[i][k] = jump[jump[i][k-1]][k-1];

    int m; cin >> m;
    for (int i=0; i<m; i++) {
        int v, p;
        cin >> v >> p;
        v--;
        if (dep[v] < p) {
            cout << "0 ";
            continue;
        }
        int w = anc(v, p);
        int ans = upper_bound(nodes[dep[v]].begin(), nodes[dep[v]].end(), w, cmp2) - lower_bound(nodes[dep[v]].begin(), nodes[dep[v]].end(), w, cmp1) - 1;
        cout << ans << ' ';
    }

    return 0;
}