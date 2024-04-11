#include <bits/stdc++.h>
using namespace std;

long long a[300010], ans, b[300010], c[300010], num, sum;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = n - 1; i >= k; i--) {
        sum -= num;
        num -= c[i];
        a[i] = sum;
        if (a[i] < b[i]) {
            long long p = (b[i] - a[i] + k - 1) / k;
            sum += p * k;
            num += p;
            c[i - k] = p;
            ans += p;
        }
    }
    for(int i = k - 1; i >= 0; i--) {
        sum -= num;
        num -= c[i];
        a[i] = sum;
        if (a[i] < b[i]) {
            long long p = (b[i] - a[i] + i) / (i + 1);
            sum += p * (i + 1);
            num += p;
            ans += p;
        }
    }
    cout << ans << endl;
    return 0;
}