#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int t, n, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        long long tot = 0;
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
        for (int i = (n + 1) / 2; i < n; i++) {
            ans.push_back({1 + i, 1});
            swap(a[i + 1], a[1]);
            tot += 1LL * i * i;
        }
        for (int i = 2; i <= (n + 1) / 2; i++) {
            ans.push_back({i, n});
            swap(a[i], a[n]);
            tot += 1LL * (n - i) * (n - i); 
        }
        cout << tot << '\n';
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " \n"[i == n];
        }
        cout << n - 1 << '\n';
        for (int i = n - 2; i >= 0; i--) {
            cout << ans[i].first << " " << ans[i].second << '\n';
        }
    }
}