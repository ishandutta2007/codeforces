/*
    13.03.2019 20:54:51
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOMEi
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

int main() {
    int n, m;
    cin >> n >> m;
    vector< int > p(n);
    vector< int > pi(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        pi[p[i]] = i;
    }
    vector< vector< int > > who(n);
    vector< int > good(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        who[u].push_back(v);
        if (v == p.back())
            good[u] = true;
    }
    int ans = 0;
    vector< int > very_good(n, false);
    show(who);
    show(good);
    for (int i = n - 2; i >= 0; --i) {
        if (good[p[i]]) {
            int cnt = ans;
            for (auto v : who[p[i]]) {
                if (pi[v] > i && !very_good[v])
                    ++cnt;
            }
            if (cnt == n - 1 - i) {
                very_good[p[i]] = true;
                ++ans;
            }
            showt(i, cnt, ans, who[p[i]], pi);
        }
    }
    show(very_good);
    cout << ans << '\n';
    return 0;
}