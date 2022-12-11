#include <bits/stdc++.h>

int main() {
    bool a, b, c, d;
    std::cin >> a >> b >> c >> d;
    bool ans = ((a ^ b) & (c | d)) ^ ((b & c) | (a ^ d));
    std::cout << ans << std::endl;
}