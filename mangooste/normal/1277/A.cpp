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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int dig = 1; dig < 10; dig++) {
            ll cur = dig;
            while (cur <= n)
                ans++, cur *= 10, cur += dig;
        }
        cout << ans << '\n';
    }
}