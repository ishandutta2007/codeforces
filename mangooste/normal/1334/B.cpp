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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        for (ll &i : a)
            cin >> i;
        sort(all(a));
        reverse(all(a));
        ll sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum >= 1LL * (i + 1) * x)
                ans = i + 1;
        }
        cout << ans << '\n';
    }
}