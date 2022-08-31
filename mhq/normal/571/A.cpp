#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
int a, b, c, l;
ll get(ll x) {
    return ((x + 2) * (x + 1)) / 2;
}
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    cin >> a >> b >> c >> l;
    ll ans = 0;
    for (int s = 0; s <= l; s++) {
        /*(x + y - z > c - b - a)
        s - 2 * z > c - b - a
        s > c - b - a + 2 * z
        s - 1 >= c - b - a + 2 * z*/
        if (c - b - a > s - 1) continue;
        if (a - b - c > s - 1) continue;
        if (b - a - c > s - 1) continue;
        int f1 = (s - 1 - (c - b - a)) / 2;
        int f2 = (s - 1 - (a - b - c)) / 2;
        int f3 = (s - 1 - (b - a - c)) / 2;
        f1++;
        f2++;
        f3++;
        ll cur1 = get(s);
        if (f1 <= s) cur1 -= get(s - f1);
        if (f2 <= s) cur1 -= get(s - f2);
        if (f3 <= s) cur1 -= get(s - f3);
        if (f1 + f2 <= s) cur1 += get(s - f1 - f2);
        if (f1 + f3 <= s) cur1 += get(s - f1 - f3);
        if (f2 + f3 <= s) cur1 += get(s - f2 - f3);
        if (f1 + f2 + f3 <= s) cur1 -= get(s - f1 - f2 - f3);
        ans += cur1;
    }
    cout << ans;
    return 0;
}