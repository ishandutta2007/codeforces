#include <bits/stdc++.h>
using ll = long long;
int main()
{
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        ll a, b, c, d;
        std::cin >> a >> b >> c >> d;
        ll max = 0;
        max    = std::max(max, std::min(a, b) * std::min(c, d));
        max    = std::max(max, std::min(a, c) * std::min(b, d));
        max    = std::max(max, std::min(a, d) * std::min(b, c));
        std::cout << max << "\n";
    }
    return 0;
}