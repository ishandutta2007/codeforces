#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> prv(n + 1, -1), ans(n + 1);
        for (int i = 0; i < n; i++) {
            int u; cin >> u;
            if (prv[u] != i - 1) {
                ans[u]++;
            }
            prv[u] = i;
        }
        int ret = numeric_limits<int>::max();
        for (int i = 1; i <= n; i++) {
            if (prv[i] != -1) {
                ans[i] += (prv[i] != n - 1);
                ret = min(ret, ans[i]);
            }
        }
        cout << ret << '\n';
    }
}