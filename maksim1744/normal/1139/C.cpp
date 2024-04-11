/*
    21.03.2019 18:41:27
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

long long mod = 1e9 + 7;

vector< vector< pair< int, int > > > g;
vector< int > col;
int color = 0;
int cnt = 0;

void dfs(int v) {
    col[v] = color;
    ++cnt;
    for (auto k : g[v]) {
        if (col[k.first] == -1 && k.second == 0)
            dfs(k.first);
    }
}

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    g.resize(n);
    col.assign(n, -1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    vector< long long > cnts;
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            cnt = 0;
            dfs(i);
            cnts.push_back(cnt);
            ++color;
        }
    }
    show(col);
    long long all = n;
    for (int i = 0; i < k - 1; ++i) {
        all = all * n % mod;
    }
    show(cnts);
    long long sm = 0;
    for (auto t : cnts) {
        sm += mpow(t, k);
    }
    sm %= mod;
    cout << ((all - sm) % mod + mod) % mod << '\n';
    return 0;
}