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
        int n;
        cin >> n;
        vector<int> ans;
        ans.pb(0);
        for (int k = 1; k * k <= n; k++) {
            int i, j;
            {
                j = k;
                i = n / k;
                if ((i + 1) * j > n)
                    ans.pb(i);
            }
            {
                i = k;
                j = n / k;
                if ((i + 1) * j > n)
                    ans.pb(i);
            }
        }
        sort(all(ans));
        ans.resize(unique(all(ans)) - ans.begin());
        cout << ans.size() << '\n';
        for (auto el : ans)
            cout << el << ' ';
        cout << '\n';
    }
}