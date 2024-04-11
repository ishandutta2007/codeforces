#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int a[100005];
int h[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) h[i] = a[i + 1] - a[i] - 1;
    sort(h + 1, h + n);
    int ans = a[n] - a[1] + 1;
    for (int i = n - 1; i >= n + 1 - k; --i) ans -= h[i];
    cout << ans << endl;
    return 0;
}