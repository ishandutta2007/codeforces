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

ll get(ll m) {
    if (m % 4 == 0 || m % 6 == 0 || m % 5 == 0)
        return 0;
    ll ans = 2 * m;
    for (ll d1 = 0; d1 <= m && d1 <= 60; d1 += 6)
        for (ll d2 = 0; d1 + d2 <= m && d2 <= 60; d2 += 5)
            ans = min(ans, ((m - d1 - d2) % 4 == 3 ? 2 : ((m - d1 - d2) % 4) * 2));
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    if (n >= 3)
        return cout << n * m - (n * m) % 2 << '\n', 0;
    if (n == 1)
        return cout << m - m % 6 + max(0LL, m % 6 - 3) * 2 << '\n', 0;
    cout << 2 * m - get(m) << '\n';
}