#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
void move(int &x, int &y, char d) {    
    if (d == 'L') {
        x--;
    } else if (d == 'R') {
        x++;
    } else if (d == 'D') {
        y--;
    } else {
        y++;
    }
}
void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        for (int j = 0; j <= i; ++j) {
            move(x, y, s[j]);
        }
        int xs = x, ys = y;
        x = y = 0;
        for (int j = 0; j < n; ++j) {
            int x1 = x, y1 = y;
            move(x1, y1, s[j]);
            if (x1 != xs || y1 != ys) {
                x = x1;
                y = y1;
            }
        }
        if (x == 0 && y == 0) {
            std::cout << xs << " " << ys << "\n";
            return;
        }
    }
    std::cout << 0 << " " << 0 << "\n";
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