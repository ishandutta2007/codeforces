#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200000];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) {
            ans = max(ans, i - l);
            l = i;
        }
    }
    ans = max(ans, n - l);
    cout << ans << "\n";
    return 0;
}