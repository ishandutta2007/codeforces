#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 10;
int n;
ll k;
ll a[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] == 0) continue;
        ll need = (a[i - 1] + k - 1) / k;
        cnt += need;
        ll left = need * k - a[i - 1];
        if (left == 0) continue;
        a[i] = max(0LL, a[i] - left);
    }
    if (a[n] > 0) {
        cnt += (a[n] + k - 1) / k;
    }
    cout << cnt;
    return 0;
}