#include <bits/stdc++.h>
using namespace std;

int n, l, u, x, y;
bool cx = true, cy = true;
set<int> se;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        se.insert(u);
    }
    for (int v : se) {
        if (se.count(v + x) == 1) {
            cx = false;
        }
        if (se.count(v + y) == 1) {
            cy = false;
        }
    }
    if (!cx && !cy) {
        cout << 0;
    } else if (!cy) {
        cout << "1\n" << x << '\n';
    } else if (!cx) {
        cout << "1\n" << y << '\n';
    } else {
        for (int v : se) {
            if (se.count(v + y - x)) {
                if (v - x > 0) {
                    return cout << "1\n" << v - x << '\n', 0;
                } else if (v + y <= l) {
                    return cout << "1\n" << v + y << '\n', 0;
                }
            }
            if (se.count(v + x + y)) {
                return cout << "1\n" << v + x << '\n', 0;
            }
        }
        cout << "2\n" << x << " " << y << '\n';
    }
}