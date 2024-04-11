#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
void solve() {
    int c1, c2, c3;
    std::cin >> c1 >> c2 >> c3;
    int a1, a2, a3, a4, a5;
    std::cin >> a1 >> a2 >> a3 >> a4 >> a5;
    if (a1 <= c1 && a2 <= c2 && a3 <= c3 && a1 + a3 + a4 <= c1 + c3 && a2 + a3 + a5 <= c2 + c3 && a1 + a2 + a3 + a4 + a5 <= c1 + c2 + c3) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}