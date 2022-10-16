#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[200005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    if (n > m) return cout << 0 << endl, 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 1;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        int p = abs(a[i] - a[j]) % m;
        ans = ans * p % m;
    }
    cout << ans << endl;
    return 0;
}