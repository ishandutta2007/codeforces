#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    partial_sum(a.begin(), a.end(), a.begin());
    vector<long long> ans;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
        ans.push_back(max(cur, (a[n - 1] - 1) / (i + 1) + 1));
        cur = max(cur, (a[i] - 1) / (i + 1) + 1);
    }
    int q; cin >> q;
    while (q--) {
        long long u; cin >> u;
        int xd = lower_bound(ans.begin(), ans.end(), u, greater<long long>()) - ans.begin();
        cout << (xd == n ? -1 : xd + 1) << '\n';
    }
}