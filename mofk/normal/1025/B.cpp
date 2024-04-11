#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005], b[200005];

long long lcm(long long x, long long y) {
    long long d = __gcd(x, y);
    return x / d * y;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    long long A = a[1], B = b[1];
    for (int i = 2; i <= n; ++i) {
        A = __gcd(A, lcm(a[i], b[i]));
        B = __gcd(B, lcm(a[i], b[i]));
    }
    if (A == 1 && B == 1) return cout << -1 << endl, 0;
    for (int i = 2; i * i <= A; ++i) if (A % i == 0) return cout << i << endl, 0;
    if (A > 1) return cout << A << endl, 0;
    for (int i = 2; i * i <= B; ++i) if (B % i == 0) return cout << i << endl, 0;
    if (B > 1) return cout << B << endl, 0;
    return 0;
}