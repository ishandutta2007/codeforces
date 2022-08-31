/*
    02.04.2019 13:49:30
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

vector<vector<int>> g;
vector<bool> u;
vector<int> c;
vector<bool> ans;

void dfs(int v) {
    u[v] = true;
    ans[v] = c[v];
    for (auto k : g[v]) {
        if (!u[k]) {
            dfs(k);
            ans[v] = ans[v] && c[k];
        }
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    c.resize(n);
    u.assign(n, false);
    ans.assign(n, false);
    int root;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p >> c[i];
        --p;
        if (p == -2) root = i;
        else g[p].push_back(i);
    }
    dfs(root);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (ans[i] && i != root) {
            cout << i + 1 << ' ';
            ++cnt;
        }
    }
    if (cnt == 0)
        cout << -1;
    cout << '\n';
    return 0;
}