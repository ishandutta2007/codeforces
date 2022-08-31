#include <bits/stdc++.h>
using namespace std;
int n;
int a[361];
int s[361];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    //cout << s[n] << " ";
    int ans = 360;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans = min(ans, abs(s[n] - 2 * (s[j] - s[i])));
        }
    }
    cout << ans;
    return 0;
}