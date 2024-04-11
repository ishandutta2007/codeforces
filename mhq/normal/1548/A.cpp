#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int cnt[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int ans = n;
    auto add = [&](int u, int v) {
        if (u > v) swap(u, v);
        ans -= (cnt[u] == 0);
        cnt[u]++;
    };
    auto del = [&](int u, int v) {
        if (u > v) swap(u, v);
        cnt[u]--;
        ans += (cnt[u] == 0);
    };
    while (m--) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int u, v;
            cin >> u >> v;
            add(u, v);
        }
        else if (tp == 2) {
            int u, v;
            cin >> u >> v;
            del(u, v);
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}