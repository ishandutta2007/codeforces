#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n, k;
int a[maxN];
int f[maxN];
int ans[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        if (f[i] == 0) {
            int t = 1;
            t += max(i - 1 - max(1, i - k) + 1, 0);
            t += max(min(n, i + k) - (i + 1) + 1, 0);
            ans[i] = t;
        }
        else {
            int t = ans[f[i]];
            int l1 = max(1, i - k);
            int r1 = min(n, i + k);
            int l2 = max(1, f[i] - k);
            int r2 = min(n, f[i] + k);
            if (l1 > r2) t += r1 - l1 + 1;
            else t += r1 - r2;
            ans[i] = t;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}