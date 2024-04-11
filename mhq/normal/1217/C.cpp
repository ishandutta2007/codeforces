#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int pref[maxN];
string s;
int pos[maxN];
int n;
void solve() {
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        pos[i + 1] = s[i] - '0';
        pref[i + 1] = pref[i] + (pos[i + 1] == 1);
    }
    int ans = 0;
    for (int r = 1; r <= n; r++) {
        int num = 0;
        for (int l = r; l >= 1; l--) {
            if ((1 << (r - l)) >= n + 5) break;
            num += pos[l] * (1 << (r - l));
            if (pos[l] != 0) {
                int will_l = r - num + 1;
                if (will_l >= 1 && will_l <= l && pref[l - 1] == pref[will_l - 1]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}