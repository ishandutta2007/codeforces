#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        long long n;
        cin >> n;
        if (n % 2050) {
            cout << -1 << '\n';
            continue;
        }
        n /= 2050;
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        cout << ans << '\n';
    }

    return 0;
}