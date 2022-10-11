#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; int w; cin >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int prv = 0;
    for (int i = 0; i < n; i++) {
        ans++;
        prv = min(prv + 1, a[i]);
    }
    // cout << prv << '\n';
    ans += a[n - 1] - prv;
    cout << accumulate(a.begin(), a.end(), 0LL) - ans;
}