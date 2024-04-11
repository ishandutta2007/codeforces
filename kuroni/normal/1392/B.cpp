#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t;
long long k, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int mx = *max_element(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = mx - a[i];
        }
        if (k % 2 == 0) {
            mx = *max_element(a + 1, a + n + 1);
            for (int i = 1; i <= n; i++) {
                a[i] = mx - a[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " \n"[i == n];
        }
    }
}