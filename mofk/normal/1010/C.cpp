#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] %= k;
    int d = k;
    for (int i = 1; i <= n; ++i) d = __gcd(d, a[i]);
    cout << k / d << endl;
    for (int i = 0; i < k; i += d) cout << i << ' ';
    cout << endl;
    return 0;
}