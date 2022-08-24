#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxN = 5 * (int)1e4 + 100;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n;
    ll best = 0;
    int mn = 105;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        best += a[i];
        mn = min(mn, a[i]);
    }
    ll sum = best;
    for (int d = 1; d <= 100; d++) {
        int mx = -1;
        for (int j = 1; j <= n; j++) {
            if (a[j] % d == 0) {
                mx = max(mx, a[j]);
            }
        }
        if (mx == -1) continue;
        best = min(best, sum - mx + mx / d + mn * d - mn);
    }
    cout << best;
}