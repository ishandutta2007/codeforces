#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 5;
long long a[maxN];
long long d;
int n;
long long s[maxN];
long long pr[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> d;
    s[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        if (s[i] > d) {
            cout << -1;
            return 0;
        }
    }
    pr[n] = s[n];
    for (int i = n - 1; i >= 1; i--) {
        pr[i] = max(pr[i + 1], s[i]);
    }
    int upd = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) continue;
        if (s[i] + upd >= 0) continue;
        long long t = -s[i] - upd;
        if (d - upd < t + pr[i]) {
            cout << -1;
            return 0;
        }
        ans++;
        upd = d - pr[i];
    }
    cout << ans;
    return 0;
}