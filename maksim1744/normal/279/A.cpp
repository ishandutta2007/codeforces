#include "bits/stdc++.h"

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 0 << '\n';
    } else if (-x + 1 < y && y <= x) {
        cout << 1 + (x - 1) * 4 << '\n';
    } else if (-y <= x && x < y) {
        cout << 2 + (y - 1) * 4 << '\n';
    } else if (x <= y && y < -x) {
        cout << 3 + (-x - 1) * 4 << '\n';
    } else {
        cout << 4 + (-y - 1) * 4 << '\n';
    }

    return 0;
}