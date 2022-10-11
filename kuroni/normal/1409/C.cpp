#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        int d = y - x, s;
        for (int i = 1; i <= d; i++) {
            if (d % i == 0 && d / i + 1 <= n) {
                s = i;
                break;
            }
        }
        int l = x % s == 0 ? s : x % s;
        l = max(l, y - (n - 1) * s);
        for (int i = 0; i < n; i++) {
            cout << l + s * i << " \n"[i == n - 1];
        }
    }
}