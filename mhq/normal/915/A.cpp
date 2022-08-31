#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[105];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    int ans = 105;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (k % a[i] == 0) {
            ans = min(ans, k / a[i]);
        }
    }
    cout << ans;
    return 0;
}