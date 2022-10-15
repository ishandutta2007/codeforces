#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

int solve(const vector<int> &a) {
    int n = a.size();
    vector<int> prefXor(n + 1);
    for (int i = 0; i < n; ++i) prefXor[i + 1] = prefXor[i] ^ a[i];
    map<int, int> last;
    last[0] = 0;
    vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + 1;
        if (last.contains(prefXor[i + 1])) {
            dp[i + 1] = min(dp[i + 1], dp[last[prefXor[i + 1]]] + (i - last[prefXor[i + 1]]));
        }
        last[prefXor[i + 1]] = i + 1;
    }
    return dp[n];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            ans += solve(a);
            a.clear();
        } else {
            a.push_back(x);
        }
    }
    ans += solve(a);
    cout << ans << '\n';
}