#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int a = n + 1, b = 0;
        while (a % 2 == 0) a /= 2, ++b;
        if (a != 1) {
            b = 0;
            while (n) n >>= 1, ++b;
            cout << ((1 << b) - 1) << '\n';
        }
        else {
            int ans = 1;
            for (int i = 2; i * i <= n; ++i) if (n % i == 0) ans = max(ans, n / i);
            cout << ans << '\n';
        }
    }
    return 0;
}