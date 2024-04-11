#include <bits/stdc++.h>

using namespace std;

int n;
int a[105];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int m = 0, s = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], m = max(m, a[i]), s += a[i];
    for (int i = m; i <= 1000; ++i) if (i * n - s > s) return cout << i << endl, 0;
    return 0;
}