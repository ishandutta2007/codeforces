#include <bits/stdc++.h>

int main() {
    int T, l, r, d;
    std::cin >> T;
    while (T--) {
        std::cin >> l >> r >> d;
        if (d < l) std::cout << d << std::endl;
        else if (r % d == 0) std::cout << r + d << std::endl;
        else std::cout << (r / d + 1) * d << std::endl;
    }
}