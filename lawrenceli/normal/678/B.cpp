#include <bits/stdc++.h>

using namespace std;

bool leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    int y; cin >> y;
    int x = 0, b = leap(y);
    for (int i = y; 1; i++) {
        x = (x + 365 + leap(i)) % 7;
        if (leap(i + 1) == b && x == 0) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}