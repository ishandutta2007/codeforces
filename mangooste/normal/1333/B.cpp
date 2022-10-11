#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> b(n);
    for (int &i : b)
        cin >> i;
    if (a[0] != b[0]) {
        cout << "NO\n";
        return;
    }
    vector<int> cnt(3, 0);
    cnt[a[0] + 1]++;
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (a[i] != b[i]) {
            int cur = (a[i] > b[i] ? cnt[0] : cnt[2]);
            if (cur == 0)
                ok = false;
        }
        cnt[a[i] + 1]++;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}