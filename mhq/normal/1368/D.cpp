#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int cnt[20];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 20; j++) {
            if (x & (1 << j)) cnt[j]++;
        }
    }
    ll ans = 0;
    vector < int > vals(n);
    for (int c = 19; c >= 0; c--) {
        for (int i = 0; i < n; i++) {
            if (cnt[c]) {
                vals[i] |= (1 << c);
                cnt[c]--;
            }
        }
    }
    for (int& v : vals) ans += 1LL * v * v;
    cout << ans;
    return 0;
}