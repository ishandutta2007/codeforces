#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i, i--;
        vector<int> cnt(n, 0);
        for (int i : a)
            cnt[i]++;
        sort(all(cnt));
        // cerr << "cnt: ";
        // for (auto i : cnt)
        //     cerr << i << ' ';
        // cerr << '\n';
        int ans = 0, sm = 0;
        for (int i = 0; i < n; i++) {
            sm += cnt[i] != 0;
            bool ok = false;
            if (i != n - 1)
                ok |= cnt.back() >= sm;
            if (i != 0)
                ok |= cnt[i - 1] - 1 >= sm;
            if (cnt[i] > 1)
                ok |= cnt[i] - 1 >= sm;
            if (ok)
                ans = sm;
        }

        cout << ans << '\n';
    }
}