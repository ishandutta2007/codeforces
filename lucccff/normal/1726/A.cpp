#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mx = a[n - 1] - a[0];
        for(int i = 1; i < n; i++) {
            mx = max(mx, a[i] - a[0]);
        }
        for(int i = 0; i < n - 1; i++) {
            mx = max(mx, a[n - 1] - a[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            mx = max(mx, a[i] - a[i + 1]);
        }
        cout << mx << endl;
    }
    return 0;
}