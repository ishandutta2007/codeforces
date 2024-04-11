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
        cin >> n;
        vector<pair<int, int>> a(n);
        for (auto& i : a)
            cin >> i.first >> i.second;
        bool ok = true;
        ok &= (a[0].first >= a[0].second);
        for (int i = 1; i < n; i++) {
            ok &= (a[i].first >= a[i].second);
            ok &= (a[i].first >= a[i - 1].first);
            ok &= (a[i].second >= a[i - 1].second);
            ok &= (a[i].first - a[i - 1].first >= a[i].second - a[i - 1].second);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}