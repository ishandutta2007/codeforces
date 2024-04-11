#include <bits/stdc++.h>
using namespace std;
int n, m;
int a1[20];
int a2[20];
int a[35];
int sum1[1 << 18];
int sum2[1 << 18];
int sum(int a, int b) {
    int x = a + b;
    if (x >= m) x = x - m;
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p = (n / 2);
    int q = n - p;
    for (int i = 0; i < p; i++) {
        a1[i] = a[i] % m;
    }
    for (int i = p; i < n; i++) {
        a2[i - p] = a[i] % m;
    }
    sum1[0] = 0;
    for (int mask = 1; mask < (1 << p); mask++) {
        for (int j = 0; j < p; j++) {
            if (mask & (1 << j)) {
                sum1[mask] = sum(sum1[mask ^ (1 << j)], a1[j]);
                break;
            }
        }
    }
    sum2[0] = 0;
    for (int mask = 1; mask < (1 << q); mask++) {
        for (int j = 0; j < q; j++) {
            if (mask & (1 << j)) {
                sum2[mask] = sum(sum2[mask ^ (1 << j)], a2[j]);
                break;
            }
        }
    }
    sort(sum1, sum1 + (1 << p));
    sort(sum2, sum2 + (1 << q));
    /*for (int i = 0; i < (1 << p); i++) {
        cout << sum1[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < (1 << q); i++) {
        cout << sum2[i] << " ";
    }*/
    if (p == 0) {
        cout << sum2[(1 << q) - 1];
        return 0;
    }
    int ptr = (1 << q) - 1;
    int ans = 0;
    for (int i = 0; i < (1 << p); i++) {
        while ((sum1[i] + sum2[ptr] >= m) && (ptr >= 1)) {
            ptr--;
        }
        ans = max(ans, sum(sum1[i], sum2[ptr]));
    }
    ans = max(ans, sum(sum1[(1 << p) - 1], sum2[(1 << q) - 1]));
    cout << ans;
    return 0;
}