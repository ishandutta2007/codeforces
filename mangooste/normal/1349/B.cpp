#include <algorithm>
#include <cassert>
#include <cmath>
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

#define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> poses;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == k)
            poses.pb(i);
    }
    if (poses.size() == 0) {
        cout << "No\n";
        return;
    }
    bool chk = false;
    chk |= (poses.size() > n / 2);
    for (int i = 2; i < n; i++) {
        vector<int> tmp;
        tmp.pb(a[i]);
        tmp.pb(a[i - 1]);
        tmp.pb(a[i - 2]);
        sort(all(tmp));
        chk |= (tmp[1] == k);
        if (tmp[0] != k && tmp[1] != k && tmp[2] != k && tmp[1] > k)
            chk = true;
    }
    for (int i = 1; i < n; i++)
        chk |= (a[i] > k && a[i - 1] > k);
    for (auto i : poses) {
        if (i > 0 && a[i - 1] >= a[i])
            chk = true;
        if (i < n - 1 && a[i + 1] >= a[i])
            chk = true;
    }

    cout << (chk ? "Yes\n" : "No\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}