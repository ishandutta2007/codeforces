#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k1, k2;
const int maxN = 1005;
ll a[maxN];
ll b[maxN];
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= (k1 + k2); i++) {
        ll mx = 0;
        int ind = -1;
        for (int j = 1; j <= n; j++) {
            if ((b[j] - a[j]) * (b[j] - a[j]) >= mx) {
                mx = (b[j] - a[j]) * (b[j] - a[j]);
                ind = j;
            }
        }
        if (b[ind] >= a[ind]) b[ind]--;
        else b[ind]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (b[i] - a[i]) * (b[i] - a[i]);
    }
    cout << ans;
    return 0;
}