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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    sort(all(a));
    vector<int> ans = {a[n / 2]};
    for (int i = 0, L = n / 2 - 1, R = n / 2 + 1; i < n - 1; i++) {
        if (i % 2 == 0)
            ans.push_back(a[L--]);
        else
            ans.push_back(a[R++]);
    }
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) 
        solve();
}