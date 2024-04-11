#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
const int N = 5000 + 10;
int n, a[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 1e18;
    for(int i = 1; i <= n; i++) {
        ll cnt = 0;
        ll now = 0;
        for(int j = i - 1; j >= 1; j--) {
            now = now / a[j] * a[j] + a[j];
            cnt += now / a[j];
        }
        now = 0;
        for(int j = i + 1; j <= n; j++) {
            now = now / a[j] * a[j] + a[j];
            cnt += now / a[j];
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(t = 1; t--; ) solve();
    return 0;
}