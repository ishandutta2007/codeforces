#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, x;
int a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt = 0, mx = a[0], mn = a[0];
        for(int i = 1; i < n; i++) {
            if (a[i] - mn > 2 * x || mx - a[i] > 2 * x) {
                cnt++;
                mx = mn = a[i];
            }
            else {
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}