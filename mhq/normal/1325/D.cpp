#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 10;
vector < pair < int, int > > g[maxN];
int deg[maxN];
int ans[maxN];
void go(const vector < ll >& f) {
    cout << f.size() << '\n';
    for (ll v : f) {
        assert(v);
        cout << v << " ";
    }
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    ll u, v;
    cin >> u >> v;
    if (u == 0 && v == 0) {
        cout << 0 << '\n';
        return 0;
    }
    if (u % 2 != v % 2 || u > v) {
        cout << -1;
        return 0;
    }
    if (u == v) {
        go({u});
    }
    ll an = (v - u) / 2;
    ll x = 0;
    ll y = 0;
    bool ok = true;
    for (int bit = 0; bit < 62; bit++) {
        int bt1 = (u >> bit) & 1;
        int bt2 = (an >> bit) & 1;
        if (bt2 == 1 && bt1 != 0) {
            ok = false;
            break;
        }
        if (bt2 == 1) {
            x |= (1LL << bit);
            y |= (1LL << bit);
        }
        else {
            if (bt1) {
                x |= (1LL << bit);
            }
        }
    }
    if (ok) {
        go({x, y});
    }
    go({u, (v - u) / 2, (v - u) / 2});
    return 0;
}