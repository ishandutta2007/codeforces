#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n, u, v, a[N], deg[N];

void solve() {
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        deg[i] = 0;
        ans += a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        deg[u]++; deg[v]++;
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < deg[i]; j++) {
            pq.push(a[i]);
        }
    }
    for (int i = 1; i < n - 1; i++) {
        cout << ans << " ";
        ans += pq.top(); pq.pop();
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}