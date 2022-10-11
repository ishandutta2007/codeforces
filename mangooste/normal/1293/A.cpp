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

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s, k;
        cin >> n >> s >> k;
        set<int> bad;
        for (int i = 0; i < k; i++) {
            int cur;
            cin >> cur;
            bad.insert(cur);
        }
        int ans = n + 1;
        for (int num = s - 2 * k; num <= s + 2 * k; num++) 
            if (1 <= num && num <= n && !bad.count(num))
                ans = min(ans, abs(s - num));
        cout << ans << '\n';
    }
}