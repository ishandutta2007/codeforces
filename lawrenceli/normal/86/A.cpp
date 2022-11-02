#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll val(int x) {
    int xo = x;
    vector<int> v;
    while (x) v.push_back(9 - x % 10), x /= 10;
    ll y = 0;
    reverse(v.begin(), v.end());
    for (int i : v) y *= 10, y += i;
    return ll(xo) * y;
}

int numdig(int x) {
    int ret = 0;
    while (x) x /= 10, ret++;
    return ret;
}

ll calc(int l, int r) {
    if (l > r) return -1;

    int dig = numdig(r);

    ll ret = max(val(l), val(r));

    int x = 4;
    for (int i = 0; i < dig - 1; i++) x = x * 10 + 9;

    if (l <= x && x <= r) ret = max(ret, val(x));

    x = 5;
    for (int i = 0; i < dig - 1; i++) x = x * 10;
    
    if (l <= x && x <= r) ret = max(ret, val(x));

    return ret;
}

int main() {
    int l, r;
    cin >> l >> r;
    ll ans = val(r);
    int n = 1;
    for (; n < 1e9; n *= 10) {
        ans = max(ans, calc(max(n, l), min(n * 10 - 1, r)));
    }

    cout << ans << endl;
}