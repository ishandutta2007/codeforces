#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, k;
const int maxN = 1e5 + 10;
int mn_l[maxN];
void solve() {
    cin >> n >> k;
    for (int i = 0; i < maxN; i++) {
        mn_l[i] = i;
    }
    int mn_val = 1e9;
    int st_val = 0;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        mn_val = min(mn_val, c);
        int le = 2;
        st_val = max(st_val, ((c / k)));
        while (le <= c) {
            int nxt = (c / (c / le));
            assert((c / le) == (c / nxt) && (c / nxt) != (c / (nxt + 1)));
            //[le .. nxt - 1]
            //[le - 1 .. nxt - 2]
            int cur_p = (c / le) + 1;
            mn_l[nxt - 1] = min(mn_l[nxt - 1], (c / cur_p));
            le = nxt + 1;
        }
    }
    for (int i = 0; i < maxN; i++) {
        mn_l[i] = min(mn_l[i], mn_val);
    }
    int best = 1e9;
    for (int i = maxN - 2; i >= st_val; i--) {
        mn_l[i] = min(mn_l[i], mn_l[i + 1]);
        best = min(best, i - mn_l[i]);
    }
    cout << best << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}