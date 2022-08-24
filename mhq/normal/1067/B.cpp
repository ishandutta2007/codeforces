#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int k;
vector < int > g[maxN];
int h[maxN];
bool used[maxN];
int prv[maxN];
int n;
void dfs(int v, int par) {
    for (int to : g[v]) {
        if (par == to) continue;
        h[to] = h[v] + 1;
        prv[to] = v;
        dfs(to, v);
    }
}
int find_nxt(int v) {
    memset(h, 0, sizeof h);
    dfs(v, -1);
    int cur_mx = 0;
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (cur_mx < h[i]) {
            pos = i;
            cur_mx = h[i];
        }
    }
    return pos;
}
void check_dfs(int cent, int par, int k) {
    if (k == 1) {
        int val = 0;
        for (int to : g[cent]) {
            if (par == to) continue;
            if (g[to].size() != 1) {
                cout << "No";
                exit(0);
            }
            val++;
        }
        if (val < 3) {
            cout << "No";
            exit(0);
        }
        return ;
    }
    int val = 0;
    for (int to : g[cent]) {
        if (par == to) continue;
        check_dfs(to, cent, k - 1);
        val++;
    }
    if (val < 3) {
        cout << "No";
        exit(0);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int a = find_nxt(1);
    int b = find_nxt(a);
    if (h[b] % 2 != 0) {
        cout << "No";
        return 0;
    }
    int cent = b;
    for (int i = 0; i < h[b] / 2; i++) {
        cent = prv[cent];
    }
    check_dfs(cent, -1, k);
    cout << "Yes";
    return 0;
}