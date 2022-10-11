#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstring>

using ll = long long;
using namespace std;

#define rep(i, L, R) for (int i = (L); i < (int)(R); ++i)
#define per(i, R, L) for (int i = (R) - 1; i >= (int)(L); --i)
#define all(a) a.begin(), a.end()
#define pb push_back

void solve() {
    ll n;
    int m;
    cin >> n >> m;
    vector<int> cnt(63, 0);
    rep(i, 0, m) {
        ll a;
        cin >> a;
        int cur = -1;
        while (a != 0) cur++, a /= 2;
        cnt[cur]++;
    }
    int ans = 0;
    rep(bit, 0, 63) {
        if (bit) cnt[bit] += cnt[bit - 1] / 2;
        if ((n >> bit) % 2 == 0) continue;
        if (cnt[bit] != 0) {
            cnt[bit]--;
            continue;
        }
        int pos = bit + 1;
        while (pos < 63 && cnt[pos] == 0) pos++;
        if (pos == 63) {
            ans = -1;
            break;
        }
        ans += pos - bit;
        rep(i, bit, pos) cnt[i]++;
        cnt[pos]--;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
}