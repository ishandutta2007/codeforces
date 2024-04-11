#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int gcd(int a, int b) {
    if (a == 0 || b == 0)
        return a + b;
    return __gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for (int& x : a) {
        cin >> x;
        if (x == 1)
            ones++;
    }
    if (ones) {
        cout << n - ones << endl;
        return 0;
    }
    int ans = 3 * n;
    for (int l = 0; l < n; l++) {
        int g = 0;
        for (int r = l; r < n; r++) {
            g = gcd(g, a[r]);
            if (g == 1)
                ans = min(ans, n + r - l - 1);
        }
    }
    if (ans == 3 * n)
        ans = -1;
    cout << ans << endl;
}