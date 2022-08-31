#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 5 * (int)1e5 + 10;
int a[maxN];
int n;
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll ans = 0;
    bool neg = false;
    bool pos = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += abs(a[i]);
        if (a[i] >= 0) pos = true;
        if (a[i] <= 0) neg = true;
    }
    int mn_abs = abs(a[1]);
    for (int i = 1; i <= n; i++) mn_abs = min(mn_abs, abs(a[i]));
    if (n == 1) {
        cout << a[1];
        return 0;
    }
    if (neg == true && pos == true) {
        cout << ans;
        return 0;
    }
    else {
        cout << ans - 2 * mn_abs;
    }
    return 0;
}