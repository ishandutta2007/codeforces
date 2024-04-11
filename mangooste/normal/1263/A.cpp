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
        vector<int> cnt(3);
        cin >> cnt[0] >> cnt[1] >> cnt[2];
        sort(all(cnt));
        if (cnt[2] <= cnt[1] + cnt[0])
            cout << (cnt[2] + cnt[1] + cnt[0]) / 2 << '\n';
        else
            cout << cnt[1] + cnt[0] << '\n';
    }
}