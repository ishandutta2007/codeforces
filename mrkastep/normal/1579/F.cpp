#include <iostream>
#include <tuple>
#include <utility>
#include <cmath>
#include <vector>
#include <numeric>

void solve() {
    long long int n, d;
    std::cin >> n >> d;
    std::vector<long long int> a(n);
    for (long long int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long int g = std::gcd(n, d);
    long long int m = 0;
    for (long long int i = 0; i < g; ++i) {
        long long int cur = 0;
        for (long long int j = 0; j < n / g * 2; ++j) {
            long long int k = (j * d + i) % n;
            if (a[k] == 1) {
                ++cur;
                m = std::max(m, cur);
            } else {
                cur = 0;
            }
        }
    }

    if (m >= n / g) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << m << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}