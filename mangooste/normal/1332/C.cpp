#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < (k + 1) / 2; i++) {
        vector<int> cnt(26, 0);
        for (int j = 1; j * k <= n; j++) {
            int a = (j - 1) * k + i;
            int b = j * k - 1 - i;
            cnt[s[a] - 'a']++;
            if (b != a)
                cnt[s[b] - 'a']++;
        }

        int mx = 0;
        int need = -1;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > mx) {
                need = j;
                mx = cnt[j];
            }
        }

        for (int j = 0; j < 26; j++)
            if (j != need)
                ans += cnt[j];
    }

    // cerr << "ans: ";
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}