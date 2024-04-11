#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve() {
    string s;
    cin >> s;
    int n = len(s);

    auto can = [&](int value) {
        array<int, 2> cnt{0, 0};
        cnt[1] = count(all(s), '1');
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == '0') cnt[0]++;
            else cnt[1]--;
            while (cnt[0] > value) {
                if (s[j] == '0') cnt[0]--;
                else cnt[1]++;
                j++;
            }
            if (cnt[1] <= value) return true;
        }
        return false;
    };

    int l = -1, r = n;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (can(mid) ? r : l) = mid;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}