#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

const int maxn = 100100;
const int maxlg = 17;

int n, dep[maxn], jump[maxn][maxlg], ord[maxn], en[maxn], cnt;
vector<int> adj[maxn];

void dfs(int cur, int p = 0) {
    int x = cnt++;
    ord[cur] = x;
    jump[x][0] = p == 0 ? x : ord[p];
    dep[x] = p == 0 ? 0 : dep[ord[p]] + 1;
    for (int i : adj[cur])
        if (i != p)
            dfs(i, cur);
    en[x] = cnt;
}

void initlca() {
    for (int k = 0; k < maxlg - 1; k++)
        for (int i = 0; i < n; i++)
            jump[i][k + 1] = jump[jump[i][k]][k];
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

int K, M;
int imp[maxn], num[2 * maxn];

int ans, cur;

int dfs2(int x) {
    //cout << "NODE: " << x << endl;
    int tot = 0;
    cur++;
    while (cur < M && num[cur] < en[x]) {
        tot += dfs2(num[cur]);
    }

    //cout << x << ' ' << tot << endl;

    if (binary_search(imp, imp + K, x)) {
        ans += tot;
        return 1;
    } else {
        if (tot >= 2) ans++, tot = 0;
        return tot;
    }
}

void go() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        int x; cin >> x;
        imp[i] = num[i] = ord[x];
    }
    sort(imp, imp + K);

    for (int i = 0; i < K; i++)
        if (jump[imp[i]][0] != imp[i] && binary_search(imp, imp + K, jump[imp[i]][0])) {
            cout << "-1\n";
            return;
        }

    M = K;
    for (int i = 0; i < K - 1; i++) num[M++] = lca(imp[i], imp[i + 1]);
    sort(num, num + M);
    M = unique(num, num + M) - num;

    //for (int i = 0; i < M; i++) cout << num[i] << ' '; cout << endl;

    ans = cur = 0;
    while (cur < M) dfs2(num[cur]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    initlca();

    int q; cin >> q;
    for (int i = 0; i < q; i++) go();
}