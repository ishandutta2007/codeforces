#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int a[N];
long long s[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1, greater<int>());
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i];
        }
        for (int i = 1; i <= q; i++) {
            int w;
            cin >> w;
            int p = lower_bound(s + 1, s + n + 1, w) - s;
            if (p > n) cout << -1 << endl;
            else cout << p << endl;
        }
    }
}