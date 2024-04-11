#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int a[maxN];
int t[maxN];
int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    int best = 0;
    int cur = 0;
    for (int j = 1; j <= k; j++) cur += a[j];
    for (int j = k + 1; j <= n; j++) cur += a[j] * t[j];
    best = cur;
    for (int i = 1; i <= n - k; i++) {
        if (t[i] == 0) cur -= a[i];
        if (t[i + k] == 0) cur += a[i + k];
        best = max(best, cur);
    }
    cout << best;
    return 0;
}