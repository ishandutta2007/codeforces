#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(0));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for(int i = 0; i < n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);
        }
        long long ans = 0;
        for(int i = 1; i < n; i++) {
            ans += abs(a[i] - a[i - 1]);
            ans += abs(b[i] - b[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}