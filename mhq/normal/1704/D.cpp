#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        vector<__int128_t> vals(n);
        __int128_t mx = 0;
        for (int i = 0; i < n; i++) {
            vector<ll> c(m);
            __int128_t d = 0;
            for (int j = 0; j < m; j++) {
                cin >> c[j];
                d += c[j] * j;
            }
            vals[i] = d;
            mx = max(mx, d);
        }
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (mx == vals[i]) pos = i;
        }
        cout << pos + 1 << " " << (ll)(mx - min(vals[0], vals[1])) << '\n';
    }
    return 0;
}