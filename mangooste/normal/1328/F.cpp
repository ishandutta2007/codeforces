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

int n, k;
vector<int> a;
vector<pair<int, int>> b;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    for (int &i : a)
        cin >> i;
    sort(all(a));
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        b.emplace_back(a[i], j - i);
        i = j;
    }
    n = b.size();
    for (auto i : b)
        if (i.second >= k)
            return cout << "0\n", 0;
    vector<pair<ll, int>> right(n);
    right[n - 1] = {0, b[n - 1].second};
    for (int i = n - 2; i >= 0; i--) {
        right[i].second = right[i + 1].second + b[i].second;
        right[i].first = right[i + 1].first + 1LL * (b[i + 1].first - b[i].first) * right[i + 1].second ;
    }
    vector<pair<ll, int>> left(n);
    left[0] = {0, b[0].second};
    for (int i = 1; i < n; i++) {
        left[i].second = left[i - 1].second + b[i].second;
        left[i].first = left[i - 1].first + 1LL * (b[i].first - b[i - 1].first) * left[i - 1].second;
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        if (left[i].second >= k && i != 0)
            ans = min(ans, left[i - 1].first + 1LL * (b[i].first - b[i - 1].first - 1) * left[i - 1].second + k - b[i].second);
        if (right[i].second >= k && i != n - 1)
            ans = min(ans, right[i + 1].first + 1LL * (b[i + 1].first - b[i].first - 1) * right[i + 1].second + k - b[i].second);
    }
    for (int i = 0; i < n; i++) {
        if (left[i].second < k && i != n - 1)
            ans = min(ans, left[i].first + right[i + 1].first + 1LL * (b[i + 1].first - b[i].first - 1) * right[i + 1].second + k - left[i].second);
        if (right[i].second < k && i != 0)
            ans = min(ans, right[i].first + left[i - 1].first + 1LL * (b[i].first - b[i - 1].first - 1) * left[i - 1].second + k - right[i].second);
    }
    cout << ans << '\n';
}