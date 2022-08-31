/*
    27.03.2019 19:11:24
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

vector<vector<int>> who;
vector<int> par;

int p(int v) {
    while (par[v] != v)
        v = par[v];
    return v;
}

void un(int u, int v) {
    u = p(u); v = p(v);
    if (who[u].size() < who[v].size()) {
        for (auto k : who[u]) {
            who[v].push_back(k);
        }
        par[u] = v;
    } else {
        for (auto k : who[v]) {
            who[u].push_back(k);
        }
        par[v] = u;
    }
}

int main() {
    int n;
    cin >> n;
    who.resize(n);
    par.resize(n);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        who[i] = {i};
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        un(u, v);
    }
    int v = p(0);
    for (auto k : who[v]) {
        cout << k + 1 << ' ';
    }
    cout << '\n';
    return 0;
}