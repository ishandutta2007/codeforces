#include <bits/stdc++.h>

using namespace std;

const int maxn = 200100;
const int maxlg = 20;

int n, p[maxn];
vector<int> adj[maxn];
int jump[maxn][maxlg];
int dep[maxn];

void dfs(int v, int d = 0) {
    dep[v] = d;
    for (int i : adj[v]) dfs(i, d + 1);
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k = maxlg - 1; k >= 0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];
    if (a == b) return a;
    for (int k = maxlg - 1; k >= 0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

int anc(int a, int d) {
    if (d < 0) return 0;
    for (int k = 0; k < maxlg; k++)
        if (d & (1<<k))
            a = jump[a][k];
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    jump[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        jump[i][0] = p[i];
        adj[p[i]].push_back(i);
    }

    for (int k = 0; k < maxlg - 1; k++)
        for (int i = 1; i <= n; i++)
            jump[i][k + 1] = jump[jump[i][k]][k];

    dfs(1);

    int c = 1, v1 = 0, v2 = 0, d1 = 0, d2 = 0;
    for (int i = 2; i <= n; i++) { while (1) {
        int l = lca(c, i);
        //cout << l << ' ' << c << ' ' << i << endl;
        if (l == c) {
            int d = dep[i] - dep[c];
            int b = anc(i, d - 1);
            if (v1 == b) {
                if (d > d1) {
                    v2 = c;
                    c = b;
                    d1 = d - 1, d2++;
                    v1 = anc(i, d - 2);
                } else break;
            } else if (d > d2) {
                if (d > d1) {
                    v1 = c;
                    c = b;
                    d1++, d2 = d - 1;
                    v2 = anc(i, d - 2);
                } else {
                    v1 = b;
                    d2 = d;
                    break;
                }
            } else break;
        } else {
            int d = dep[i] + dep[c] - 2 * dep[l];
            int l = lca(p[c], i);
            int x;
            if (l == p[c]) x = anc(i, dep[i] - dep[p[c]] - 1);
            else x = p[p[c]];
            if (v1 == p[c]) {
                if (d > d1) {
                    v2 = c;
                    c = p[c];
                    d1 = d - 1, d2++;
                    v1 = x;
                } else break;
            } else if (d > d2) {
                if (d > d1) {
                    v1 = c;
                    c = p[c];
                    d1++, d2 = d - 1;
                    v2 = x;
                } else {
                    v2 = p[c];
                    d2 = d;
                    break;
                }
            } else break;
        }

        if (d1 < d2) swap(d1, d2), swap(v1, v2);

        }

        if (d1 < d2) swap(d1, d2), swap(v1, v2);

        //cout << c << ' ';
        cout << d1 + d2 << ' ';
        //cout << v1 << ' ' << d1 << ' ' << v2 << ' ' << d2 << endl;
    }
    cout << '\n';
}