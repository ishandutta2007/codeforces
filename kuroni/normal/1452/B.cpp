#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, t, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long th = 1LL * (*max_element(a + 1, a + n + 1)) * (n - 1);
        long long su = accumulate(a + 1, a + n + 1, 0LL);
        if (th < su) {
            th = su + (n - 1 - su % (n - 1)) % (n - 1);
        }
        cout << th - su << '\n';
    }
}