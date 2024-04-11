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

long long inf = 1e9l * 1e9l;

vector< vector< int > > g;
vector< long long > s;
vector< long long > a;
vector< bool > u;
long long ss = 0;

void dfs(int v, int h = 1, int p = -1) {
    u[v] = true;
    if (h) {
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k, h ^ 1, v);
            }
        }
    } else {
        long long mn = inf;
        show(mn);
        long long sm = 0;
        long long cnt = 0;
        for (auto k : g[v]) {
            if (!u[k]) {
                mn = min(mn, s[k]);
                ++cnt;
                dfs(k, h ^ 1, v);
                if (s[k] - s[p] < 0) {
                    cout << -1 << '\n';
                    exit(0);
                }
                sm += s[k] - s[p];
            }
        }
        if (mn == inf) return;
        ss += sm - cnt * (mn - s[p]) + (mn - s[p]);

    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    s.resize(n);
    a.assign(n, 0);
    u.assign(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] == -1) s[i] = 0;
    }
    printTree(g, 0, s);
    dfs(0);
    cout << ss + s[0] << '\n';
    return 0;
}