#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5005;
vector < int > g[maxN];
int a[maxN], b[maxN];
int n, m;
bool ALL_OK = true;
int clr[maxN];
void dfs(int v) {
    if (!ALL_OK) return;
    clr[v] = 1;
    for (int to : g[v]) {
        if (clr[to] == 1) {
            ALL_OK = false;
            break;
        }
        else if (clr[to] == 0) {
            dfs(to);
        }
    }
    clr[v] = 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (clr[i] == 0) {
            dfs(i);
        }
    }
    if (ALL_OK) {
        cout << 1 << '\n';
        for (int i = 1; i <= m; i++) cout << 1 << " ";
    }
    else {
        cout << 2 << "\n";
        for (int i = 1; i <= m; i++) {
            if (a[i] < b[i]) cout << 1 << " ";
            else cout << 2 << " ";
        }
    }
    return 0;
}