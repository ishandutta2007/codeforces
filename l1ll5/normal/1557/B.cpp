#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        auto b = a;
        map<int, int> mp;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i += 1) mp[b[i]] = i;
        int cur = 1;
        for (int i = 1; i < n; i += 1)
            cur += (mp[a[i - 1]] + 1 != mp[a[i]]);
        cout << ((cur <= k) ? "Yes\n" : "No\n");
    }
}