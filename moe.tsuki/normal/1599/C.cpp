#include <bits/stdc++.h>

using namespace std;

long long C(long long n, long long k) {
    if (k < 0 || n < k) return 0;
    long long res = 1, fac = 1;
    for (int i = 0; i < k; i++)
        res *= n - i;
    for (int i = 1; i <= k; i++)
        fac *= i;
    return res / fac;
}
signed main() {
    long long n;
    long double p;
    cin >> n >> p;
    const auto check = [n, p](long long k) -> bool {
        long double x = (C(k, 3) + C(k, 2) * C(n-k, 1) + C(k, 1) * C(n-k, 2) * 0.5)
            / static_cast<long double>(C(n, 3));
        // cerr << "x = " << x << endl;
        return x >= p;
    };
    // cout << check(6) << endl;
    // return 0;
    long long L = 0, R = n;
    while (R != L) {
        long long M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M+1;
        }
    }
    cout << L << '\n';
}