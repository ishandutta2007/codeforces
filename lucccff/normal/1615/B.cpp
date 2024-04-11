#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, l, r, n;
    cin >> t;
    while(t--) {
        int ans = 0;
        cin >> l >> r;
        l--;
        for(int i = 1; i < 3e5; i <<= 1) {
            n = (r / (2 * i) - l / (2 * i)) * i;
            n += max(0, r % (2 * i) - i + 1);
            n -= max(0, l % (2 * i) - i + 1);
            ans = max(ans, n);
        }
        cout << r - l - ans << endl;
    }
}