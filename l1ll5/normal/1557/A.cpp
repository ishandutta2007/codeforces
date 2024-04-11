#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 5;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    cout << fixed << setprecision(10);
    while (T--) {
        int n;
        cin >> n;
        LL mx = -1e18, sum = 0;
        for (int i = 1; i <= n; i += 1) {
            int x;
            cin >> x;
            mx = max(mx, (LL)x);
            sum += x;
        }
        cout << mx + (double)(sum - mx) / (n - 1) << '\n';
    }
}